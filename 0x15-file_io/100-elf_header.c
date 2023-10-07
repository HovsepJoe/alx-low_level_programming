#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - this function prints address
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_addr(char *ptr)
{
	int p;
	int start;
	char ss;

	printf("  Entry point address:               0x");

	ss = ptr[4] + '0';
	if (ss == '1')
	{
		start = 26;
		printf("80");
		for (p = start; p >= 22; p--)
		{
			if (ptr[p] > 0)
				printf("%x", ptr[p]);
			else if (ptr[p] < 0)
				printf("%x", 256 + ptr[p]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (ss == '2')
	{
		start = 26;
		for (p = start; p > 23; p--)
		{
			if (ptr[p] >= 0)
				printf("%02x", ptr[p]);

			else if (ptr[p] < 0)
				printf("%02x", 256 + ptr[p]);

		}
	}
	printf("\n");
}

/**
 * print_type - this funtion prints type
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_type(char *ptr)
{
	char typ = ptr[16];

	if (ptr[5] == 1)
		typ = ptr[16];
	else
		typ = ptr[17];

	printf("  Type:                              ");
	if (typ == 0)
		printf("NONE (No file typ)\n");
	else if (typ == 1)
		printf("REL (Relocatable file)\n");
	else if (typ == 2)
		printf("EXEC (Executable file)\n");
	else if (typ == 3)
		printf("DYN (Shared object file)\n");
	else if (typ == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", typ);
}

/**
 * print_osabi - this function prints OS/ABI
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_osabi(char *ptr)
{
	char osb = ptr[7];

	printf("  OS/ABI:                            ");
	if (osb == 0)
		printf("UNIX - System V\n");
	else if (osb == 2)
		printf("UNIX - NetBSD\n");
	else if (osb == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osb);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - this function prints version
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_version(char *ptr)
{
	int ver = ptr[6];

	printf("  Version:                           %d", ver);

	if (ver == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}

/**
 * print_data - this function print the data
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}

/**
 * print_magic - this function prints magic
 * information
 * @ptr: the magic
 *
 * Return: returns null
 */

void print_magic(char *ptr)
{
	int byt;

	printf("  Magic:  ");

	for (byt = 0; byt < 16; byt++)
		printf(" %02x", ptr[byt]);

	printf("\n");

}

/**
 * check_sys - this function checks the version
 * @ptr: the magiic
 *
 * Return: returns null
 */

void check_sys(char *ptr)
{
	char ss = ptr[4] + '0';

	if (ss == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (ss == '1')
		printf("  Class:                             ELF32\n");

	if (ss == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - this function checks if it is an elf
 * @ptr: the magic
 *
 * Return: returns 1 or 0
 */

int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - entry point
 * @argc: arguement
 * @argv: vector
 *
 * Return: return will be 0
 */

int main(int argc, char *argv[])
{
	int fdesc, read_rt;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fdesc = open(argv[1], O_RDONLY);

	if (fdesc < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fdesc, 0, SEEK_SET);
	read_rt = read(fdesc, ptr, 27);

	if (read_rt == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(ptr);
	close(fdesc);

	return (0);
}

