#include "main.h"
#include <elf.h>

void elf_checker(unsigned char *e_ident);
void Magic_display(unsigned char *e_ident);
void Class_display(unsigned char *e_ident);
void Data_display(unsigned char *e_ident);
void Version_display(unsigned char *e_ident);
void OS_ABI_display(unsigned char *e_ident);
void ABI_Version_display(unsigned char *e_ident);
void Type_display(unsigned int e_type, unsigned char *e_ident);
void Entry_pt_display(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
  *elf_checker - Checks whether a file is an ELF file.
  *
  *@c: The pointer to an array containing the ELF magic numbers.
  *
  *Desc: If the file is not an ELF file - exit code 98.
  */
void elf_checker(unsigned char *c)
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
  *Magic_display - Prints the magic numbers of an ELF header.
  *
  *@c: The pointer to an array containing the ELF magic numbers.
  *
  *Desc: Spaces separate magic numbers.
  */
void Magic_display(unsigned char *c)
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
  *Class_display - Prints the class of an ELF header.
  *
  *@c: A pointer to an array containing the ELF class.
  *
  *Desc: prints class of an ELF file
  */
void Class_display(unsigned char *c)
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
  *Data_display - Fuction that Prints the data of an ELF header.
  *
  *@c: A pointer to an array containing the ELF class.
  *
  *Desc: print the data of an elf header
  */
void Data_display(unsigned char *c)
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
  *Version_display - Prints the version of an ELF header.
  *
  *@c: A pointer to an array containing the ELF version.
  *
  *Desc: prints the version of elf header
  */
void Version_display(unsigned char *c)
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
  *OS_ABI_display - Prints the OS/ABI of an ELF header.
  *
  *@c: A pointer to an array containing the ELF version.
  *
  *Desc: print OS/ABI of an ELF header.
  */
void OS_ABI_display(unsigned char *c)
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
  *ABI_Version_display - Prints the ABI version of an ELF header.
  *
  *@c: A pointer to an array containing the ELF ABI version.
  *
  *Desc: prints the ABI version
  */
void ABI_Version_display(unsigned char *c)
{
	printf("  ABI Version:                       %d\n",
	       c[EI_ABIVERSION]);
}

/**
  *Type_display - Prints the type of an ELF header.
  *
  *@e: The ELF type.
  *
  *@c: A pointer to an array containing the ELF class.
  */
void Type_display(unsigned int e, unsigned char *c)
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
  *Entry_pt_display - Prints the entry point of an ELF header.
  *
  *@ee: The address of the ELF entry point.
  *
  *@c: A pointer to an array containing the ELF class.
  */
void Entry_pt_display(unsigned long int ee, unsigned char *c)
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
	elf_checker(header->e_ident);
	printf("ELF Header:\n");
	Magic_display(header->e_ident);
	Class_display(header->e_ident);
	Data_display(header->e_ident);
	Version_display(header->e_ident);
	OS_ABI_display(header->e_ident);
	ABI_Version_display(header->e_ident);
	Type_display(header->e_type, header->e_ident);
	Entry_pt_display(header->e_entry, header->e_ident);
	free(header);
	close_elf(o);
	return (0);
}
