#include "main.h"

/**
 * create_file - Creates a file with the specified content.
 * @filename: The name of the file to create or overwrite.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t b_written = 0;
	mode_t mode = S_IRUSR | S_IWUSR; /* rw------- */

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		b_written = write(fd, text_content, strlen(text_content));

		if (b_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
