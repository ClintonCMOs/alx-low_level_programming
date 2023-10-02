#include "main.h"

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char **argv)
{
	int source_fd, dest_fd;

	if (check_arguments(argc) != 0)
		return (97);
	if (open_files(argv[1], argv[2], &source_fd, &dest_fd) != 0)
		return (98);
	if (copy_file_contents(source_fd, dest_fd) != 0)
		return (99);
	if (close(source_fd) == -1 || close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		return (100);
	}
	return (0);
}

/**
 * check_arguments - Checks the command-line arguments.
 * @argc: The number of command-line arguments.
 *
 * Return: 0 if arguments are valid, otherwise an error code.
 */
int check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (1);
	}
	return (0);
}
/**
 * open_files - Opens source and destination files.
 * @source: The source file path.
 * @destination: The destination file path.
 * @source_fd: A pointer to store the source file descriptor.
 * @dest_fd: A pointer to store the destination file descriptor.
 *
 * Return: 0 if files are opened successfully, otherwise an error code.
 */
int open_files(char *source, char *destination, int *source_fd, int *dest_fd)
{
	*source_fd = open(source, O_RDONLY);

	if (*source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		return (1);
	}
	*dest_fd = open(destination, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (*dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
		close(*source_fd);
		return (1);
	}
	return (0);
}
/**
 * copy_file_contents - Copies the content from source to destination file.
 * @source_fd: The source file descriptor.
 * @dest_fd: The destination file descriptor.
 *
 * Return: 0 on success, or an error code on failure.
 */
int copy_file_contents(int source_fd, int dest_fd)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);

		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			return (1);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		return (1);
	}
	return (0);
}
