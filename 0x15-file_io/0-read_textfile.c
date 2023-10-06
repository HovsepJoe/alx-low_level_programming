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
	int rw, oreads, owrites;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	rw = open(filename, O_RDONLY, 600);
	if (rw == -1)
	{
		free(buffer);
		return (0);
	}
	oreads = read(rw, buffer, letters);
	if (oreads == -1)
	{
		free(buffer);
		return (0);
	}

	owrites = write(STDOUT_FILENO, buffer, oreads);
	if (owrites == -1 || owrites != oreads)
	{
		return (0);
	}

	free(buffer);
	close(rw);
	return (owrites);
}
