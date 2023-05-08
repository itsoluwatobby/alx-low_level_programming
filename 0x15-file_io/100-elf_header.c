#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - function that displays the information contained in the ELF
 *	header at the start of an ELF file.
 * @argc: count of arguments parsed in
 * @argv: arguments parsed in
 * Return: onsuccess (1), else (0)
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *start;
	int view, rd;

	view = open(argv[1], O_RDONLY);
	if (view == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	start = malloc(sizeof(Elf64_Ehdr));
	if (start == NULL)
	{
		exit_elf_helper(view);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(view, start, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(start);
		exit_elf_helper(view);
		dprintf(STDERR_FILENO, "Error: %s: No such file\n", argv[1]);
		exit(98);
	}

	elf_helper(start->e_ident);
	printf("ELF Header:\n");
	get_magic(start->e_ident);
	get_class(start->e_ident);
	get_data(start->e_ident);
	get_version(start->e_ident);
	get_os_abi(start->e_ident);
	get_abi(start->e_ident);
	get_type(start->e_ident, start->e_type);
	get_starter(start->e_ident, start->e_entry);

	free(start);
	exit_elf_helper(view);

	return (0);
}

/*
 * elf_helper - function that checks if a file is an ELF file
 * @dist: pointer to an array of ELF magic numbers
 *
 * Desc: exit with 98 if fileis not an ELF
 */

void elf_helper(unsigned char *dist)
{
	int i = 0;

	while (i < 4)
	{
		if (dist[i] != 127 && dist[i] != 'E' && dist[i] != 'L'
				&& dist[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		i++;
	}
}

/**
 * get_magic - function that prints an ELF header magic number
 * @dist: pointer to an array of ELF magic numbers
 *
 * Desc: magic numbers are separated by space
 */

void get_magic(unsigned char *dist)
{
	int i = 0;

	while (i < EI_NIDENT)
	{
		printf("%02x", dist[i]);
		if (i == EI_NIDENT)
			printf("\n");
		else
			printf(" ");
		i++;
	}
}

/**
 * get_class - function that prints the class of an ELF header
 * @dist: pointer to an array of ELF class
 */

void get_class(unsigned char *dist)
{
	printf(" Class:               ");

	switch (dist[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", dist[EI_CLASS]);
	}
}

/**
 * get_data - function that prints the data of an ELF header
 * @dist: pointer to an array of ELF data
 */

void get_data(unsigned char *dist)
{
	printf(" Data:               ");

	switch (dist[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's compliment, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", dist[EI_DATA]);
	}
}

/**
 * get_os_abi - function that prints the OS/ABI of an ELF header
 * @dist: pointer to an array of ELF version
 */

void get_os_abi(unsigned char *dist)
{
	printf(" OS/ABI:               ");

	switch (dist[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRUE64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", dist[EI_OSABI]);
	}
}

/**
 * get_abi - function that prints the ABI of an ELF header
 * @dist: pointer to an array of ELF ABI version
*/

void get_abi(unsigned char *dist)
{
	printf(" ABI Version:               %d\n", dist[EI_ABIVERSION]);
}

/**
 * get_type - function that prints the type of an ELF header
 * @type: ELF type
 * @dist: pointer to an array of ELF type
 */

void get_type(unsigned char *dist, unsigned int type)
{
	if (dist[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf(" Type:               ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * get_starter - function that prints the starting point of an ELF header
 * @starter: address of an ELF header starting point
 * @dist: pointer to an array of ELF type
 */

void get_starter(unsigned char *dist, unsigned long int starter)
{
	printf(" Entry point address:      ");

	if (dist[EI_DATA] == ELFDATA2MSB)
	{
		starter = ((starter << 8) & 0xFF00FF00) |
			((starter >> 8) & 0xFF00FF);
		starter = (starter << 16) | (starter >> 16);
	}
	if (dist[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)starter);
	else
		printf("%#lx\n", starter);
}

/**
 * exit_elf_helper - function that closes an ELF file
 * @elf: file descriptor of the ELF file
 *
 * Desc: exit with 98, if file cannot be closed
 */

void exit_elf_helper(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * get_version - function that prints the version of an ELF header
 * @dist: pointer to an array of ELF version
 */

void get_version(unsigned char *dist)
{
	printf(" Version:               %d", dist[EI_VERSION]);

	switch (dist[EI_VERSION])
	{
		case EV_CURRENT:
			printf("current\n");
			break;
		default:
			printf("\n");
	}
}
