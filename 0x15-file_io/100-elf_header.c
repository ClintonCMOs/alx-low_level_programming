#include "main.h"
#include <elf.h>

void elf_finder(unsigned char *e_ident);
void magic_printer(unsigned char *e_ident);
void class_printer(unsigned char *e_ident);
void data_printer(unsigned char *e_ident);
void version_printer(unsigned char *e_ident);
void osabi_printer(unsigned char *e_ident);
void abi_printer(unsigned char *e_ident);
void type_printer(unsigned int e_type, unsigned char *e_ident);
void entry_printer(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
  *elf_finder - Checks if a file is an ELF file.
  *
  *@c: The pointer to an array containing the ELF magic numbers.
  *
  *Desc: If the file is not an ELF file - exit code 98.
  */
void elf_finder(unsigned char *c)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (c[i] != 127 && c[i] != 'E' && c[i] != 'L' && c[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
  *magic_printer - Prints the magic numbers of an ELF header.
  *
  *@c: The pointer to an array containing the ELF magic numbers.
  *
  *Desc: Spaces separate magic numbers.
  */
void magic_printer(unsigned char *c)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", c[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
  *class_printer - Prints the class of an ELF header.
  *
  *@c: A pointer to an array containing the ELF class.
  *
  *Desc: prints class of an ELF file
  */
void class_printer(unsigned char *c)
{
	printf("  Class:                             ");
	switch (c[EI_CLASS])
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
		printf("<unknown: %x>\n", c[EI_CLASS]);
	}
}

/**
  *data_printer - Fuction that Prints the data of an ELF header.
  *
  *@c: A pointer to an array containing the ELF class.
  *
  *Desc: print the data of an elf header
  */
void data_printer(unsigned char *c)
{
	printf("  Data:                              ");
	switch (c[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", c[EI_CLASS]);
	}
}

/**
  *version_printer - Prints the version of an ELF header.
  *
  *@c: A pointer to an array containing the ELF version.
  *
  *Desc: prints the version of elf header
  */
void version_printer(unsigned char *c)
{
	printf("  Version:                           %d",
	       c[EI_VERSION]);
	switch (c[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
  *osabi_printer - Prints the OS/ABI of an ELF header.
  *
  *@c: A pointer to an array containing the ELF version.
  *
  *Desc: print OS/ABI of an ELF header.
  */
void osabi_printer(unsigned char *c)
{
	printf("  OS/ABI:                            ");

	switch (c[EI_OSABI])
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
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", c[EI_OSABI]);
	}
}
/**
  *abi_printer - Prints the ABI version of an ELF header.
  *
  *@c: A pointer to an array containing the ELF ABI version.
  *
  *Desc: prints the ABI version
  */
void abi_printer(unsigned char *c)
{
	printf("  ABI Version:                       %d\n",
	       c[EI_ABIVERSION]);
}

/**
  *type_printer - Prints the type of an ELF header.
  *
  *@e: The ELF type.
  *
  *@c: A pointer to an array containing the ELF class.
  */
void type_printer(unsigned int e, unsigned char *c)
{
	if (c[EI_DATA] == ELFDATA2MSB)
		e >>= 8;
	printf("  Type:                              ");
	switch (e)
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
		printf("<unknown: %x>\n", e);
	}
}

/**
  *entry_printer - Prints the entry point of an ELF header.
  *
  *@ee: The address of the ELF entry point.
  *
  *@c: A pointer to an array containing the ELF class.
  */
void entry_printer(unsigned long int ee, unsigned char *c)
{
	printf("  Entry point address:               ");

	if (c[EI_DATA] == ELFDATA2MSB)
	{
		ee = ((ee << 8) & 0xFF00FF00) | ((ee >> 8) & 0xFF00FF);
		ee = (ee << 16) | (ee >> 16);
	}
	if (c[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ee);
	else
		printf("%#lx\n", ee);
}

/**
  *close_elf - The function that loses an ELF file.
  *
  *@elf: The file descriptor of the ELF file.
  *
  *Desc: exit code 98 if file cannot be closed.
  */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
  *main - Displays the infor in the ELF header at the start of an ELF file.
  *
  *@argc: The number of arguments supplied to the program.
  *
  *@argv: An array of pointers to the arguments.
  *
  *Return: 0 on success.
  *
  *Description: exit code 98 if fail or not elf file
  */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	elf_finder(header->e_ident);
	printf("ELF Header:\n");
	magic_printer(header->e_ident);
	class_printer(header->e_ident);
	data_printer(header->e_ident);
	version_printer(header->e_ident);
	osabi_printer(header->e_ident);
	abi_printer(header->e_ident);
	type_printer(header->e_type, header->e_ident);
	entry_printer(header->e_entry, header->e_ident);
	free(header);
	close_elf(o);
	return (0);
}
