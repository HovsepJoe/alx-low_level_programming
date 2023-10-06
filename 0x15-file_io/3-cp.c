#include "main.h"
#include <stdio.h>

/**
 * error_file - if files can be opened function
 * @file_frm: cp file_from
 * @file_to: cp file_to
 * @argv: argument
 *
 * Return:return null
 */


void error_file(int file_frm, int file_to, char *argv[])
{
	if (file_frm == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from the file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - this function check the code
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int file_frm, file_to, error_c;
	ssize_t nchar, nwrites;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: copy file_frm file_to");
		exit(97);
	}

	file_frm = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_frm, file_to, argv);

	nchar = 1024;
	while (nchar == 1024)
	{
		nchar = read(file_frm, buf, 1024);
		if (nchar == -1)
			error_file(-1, 0, argv);
		nwrites = write(file_to, buf, nchar);
		if (nwrites == -1)
			error_file(0, -1, argv);
	}

	error_c = close(file_frm);
	if (error_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdesc %d\n", file_frm);
		exit(100);
	}

	error_c = close(file_to);
	if (error_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdesc %d\n", file_frm);
		exit(100);
	}
	return (0);
}
