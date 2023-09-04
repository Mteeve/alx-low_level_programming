#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf_file(unsigned char *e_ident);
void print_magic_numbers(unsigned char *e_ident);
void print_class_type(unsigned char *e_ident);
void print_data_encoding(unsigned char *e_ident);
void print_version_number(unsigned char *e_ident);
void print_osabi_type(unsigned char *e_ident);
void print_elf_type(unsigned int e_type, unsigned char *e_ident);
void print_entry_point(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);

void check_elf_file(unsigned char *e_ident)
{
    for (int i = 0; i < 4; ++i)
        (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F') ? exit(98) : 0;
}

void print_magic_numbers(unsigned char *e_ident)
{
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i)
        printf("%02x%s", e_ident[i], (i == EI_NIDENT - 1) ? "\n" : " ");
}

void print_class_type(unsigned char *e_ident)
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

void print_data_encoding(unsigned char *e_ident)
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

void print_version_number(unsigned char *e_ident)
{
    printf("  Version:                           %d%s", e_ident[EI_VERSION], (e_ident[EI_VERSION] == EV_CURRENT) ? " (current)\n" : "\n");
}

void print_osabi_type(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI]) 
    {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
    }
}
