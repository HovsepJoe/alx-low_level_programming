/**
 * create_file - file creation function
 * @filename: name of file
 * @text_content: content written in file
 *
 * Return: return 1 if success or rather -1.
 */

int create_file(const char *filename, char *text_content)
{
	int fdesc;
	int nlett;
	int rwrites;

	if (!filename)
		return (-1);

	fdesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fdesc == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlett = 0; text_content[nlett]; nlett++)
		;

	rwrites = write(fdesc, text_content, nlett);

	if (rwrites == -1)
		return (-1);

	close(fdesc);

	return (1);
}
