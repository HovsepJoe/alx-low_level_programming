#include "main.h"

/**
 * append_text_to_file - appending text function
 * @filename: name of file
 * @text_content: content added
 *
 * Return: returns 1 if the file exist or rather -1
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int fdesc;
	int nlett;
	int rwrites;

	if (!filename)
		return (-1);

	fdesc = open(filename, O_WRONLY | O_APPEND);

	if (fdesc == -1)
		return (-1);

	if (text_content)
	{
		for (nlett = 0; text_content[nlett]; nlett++)
			;

		rwrites = write(fdesc, text_content, nlett);

		if (rwrites == -1)
			return (-1);
	}

	close(fdesc);

	return (1);
}
