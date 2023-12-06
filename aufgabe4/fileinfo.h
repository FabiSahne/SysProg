//#include <errno.h>
#ifndef FILEINFO_H
#define FILEFINF_H
#include <stddef.h>
#include <linux/limits.h>
#endif
#include <stdint.h>

typedef struct fileinfo fileinfo;
enum filetype
{
    filetype_regular,
    filetype_directory,
    filetype_other
};

struct fileinfo
{
    char name[NAME_MAX + 1];
    enum filetype type;
    fileinfo* next;
    union
    {
        size_t size;
        fileinfo* list;
    };

};

fileinfo* fileinfo_create(char* path);

void fileinfo_print(fileinfo* file);

void fileinfo_destroy(fileinfo* file);
