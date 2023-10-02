#include "main.h"
#define BUFFER_SIZE 1024

void print_error_and_exit(int code, const char *msg);
int open_file(const char *filename, int mode, mode_t permissions);
void copy_file(int src_fd, int dest_fd);

/**
 * print_error_and_exit - Print an error message and exit with the given code.
 * @code: The error code to exit with.
 * @msg: The error message to print.
 */
void print_error_and_exit(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(code);
}

/**
 * open_file - Open a file with the specified mode and permissions.
 * @filename: The name of the file to open.
 * @mode: The mode to open the file with.
 * @permissions: The permissions to set for the file.
 *
 * Return: The file descriptor of the opened file, or -1 on error.
 */
int open_file(const char *filename, int mode, mode_t permissions)
{
	int fd = open(filename, mode, permissions);

	if (fd == -1)
		print_error_and_exit(99, "Can't open file");

	return (fd);
}

/**
 * copy_file - Copy the contents of one file to another.
 * @src_fd: The source file descriptor.
 * @dest_fd: The destination file descriptor.
 */
void copy_file(int src_fd, int dest_fd)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
			print_error_and_exit(99, "Can't write to destination file");
	}
	if (bytes_read == -1)
		print_error_and_exit(98, "Can't read from source file");
}
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char **argv)
{
	int src_fd, dest_fd;

	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to");

	src_fd = open_file(argv[1], O_RDONLY, 0664);
	dest_fd = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	copy_file(src_fd, dest_fd);

	if (close(src_fd) == -1 || close(dest_fd) == -1)
		print_error_and_exit(100, "Can't close file descriptors");

	return (0);
}

