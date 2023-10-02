#include "main.h"
#define BUFFER_SIZE 1024
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_source, fd_destination, nread;
	char b[BUFFER_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
	exit(97);
	fd_source = open(argv[1], O_RDONLY);
	if (fd_source == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	fd_destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_destination == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	exit(99);
	while ((nread = read(fd_source, b, BUFFER_SIZE)) > 0)
	{
		if (write(fd_destination, b, nread) != nread)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	if (nread == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	if (close(fd_source) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_source);
	exit(100);
	if (close(fd_destination) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_destination);
	exit(100);
	return (0);
}
