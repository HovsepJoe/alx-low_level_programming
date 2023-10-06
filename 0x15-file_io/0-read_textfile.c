#include "main.h"

/**
 * read_textfile - this reads a file
 * @filename: file
 * @letters: number of chars
 *
 * Return: returns actual number of letters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d, f_read, f_write;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_d = open(filename, O_RDONLY, 600);
	if (file_d == -1)
	{
		free(buffer);
		return (0);
	}
	f_read = read(file_d, buffer, letters);
	if (f_read == -1)
	{
		free(buffer);
		return (0);
	}

	f_write = write(STDOUT_FILENO, buffer, oreads);
	if (f_write == -1 || f_write != f_read)
	{
		return (0);
	}

	free(buffer);
	close(file_d);
	return (f_write);
}
