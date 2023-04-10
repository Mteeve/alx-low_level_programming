#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/* Check if the given file is an ELF file. */
void check_elf(unsigned char *e_ident)
{
for (int i = 0; i < 4; ++i)
(e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F') ? exit(98) : 0;
}

/* Print the magic numbers of an ELF header. */
void print_magic(unsigned char *e_ident)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; ++i)
printf("%02x%s", e_ident[i], (i == EI_NIDENT - 1) ? "\n" : " ");
}

/* Print the class of an ELF header. */
void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE: printf("none\n"); break;
case ELFCLASS32: printf("ELF32\n"); break;
case ELFCLASS64: printf("ELF64\n"); break;
default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
}
}

/* Print the data of an ELF header. */
void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE: printf("none\n"); break;
case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
default: printf("<unknown: %x>\n", e_ident[EI_CLASS]); break;
}
}

/* Print the version of an ELF header. */
void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d%s", e_ident[EI_VERSION], (e_ident[EI_VERSION] == EV_CURRENT) ? " (current)\n" : "\n");
}

/* Print the OS/ABI of an ELF header. */
void print_osabi(unsigned char *e_ident) {
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI]) 
{
case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;

}
