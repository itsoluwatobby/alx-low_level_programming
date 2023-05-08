#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void get_os_abi(unsigned char *dist);
void get_magic(unsigned char *dist);
void get_abi(unsigned char *dist);
void get_version(unsigned char *dist);
void elf_helper(unsigned char *dist);
void get_data(unsigned char *dist);
void get_class(unsigned char *dist);
void get_type(unsigned char *dist, unsigned int type);
void get_starter(unsigned char *dist, unsigned long int starter);
void exit_elf_helper(int elf);

#endif
