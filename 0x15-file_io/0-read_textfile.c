#include <stdio.h>
#include "main.h"

/**
 * read_textfile - this reads a file
 * @filename: file
 * @letters: number of chars
 *
 * Return: returns 1 or 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f_desc;
	ssize_t f_read, f_write;
	char *buff;

	if (!filename)
		return (0);

	f_desc = open(filename, O_RDONLY);
	if (f_desc == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	f_read = read(f_desc, buff, letters);
	f_write = write(STOUT_FILENO, buff, f_read);

	close(f_desc);

	free(buff);

	return (f_write);
}
