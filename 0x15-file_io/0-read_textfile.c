#include "main.h"

/**
 * read_textfile - Reads and prints a text file to the POSIX std out.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 *         0 if the file cannot be opened, read, or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t pF, b_read, b_written;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	pF = open(filename, O_RDONLY);
	b_read = read(pF, buffer, letters);
	b_written = write(STDOUT_FILENO, buffer, b_read);
	if (b_read == -1 || pF == -1 || b_written != b_read || b_written == -1)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(pF);
	return (b_written);
}
