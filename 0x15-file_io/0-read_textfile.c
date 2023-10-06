#include <stdio.h>
#include "main.h"

/**
 * read_textfile - reads a text file
 * @filename: name of file
 * @letters: no of letters
 *
 * Return: 1 for success 0 for failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t _nrd, _nwr;
	char *buf;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	_nrd = read(fd, buf, letters);
	_nwr = write(STDOUT_FILENO, buf, _nrd);

	close(fd);

	free(buf);

	return (_nwr);
}
