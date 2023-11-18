//#include <errno.h>
#ifndef FILEINFO_H
#define FILEFINF_H
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
    char* name;
    enum filetype type;
    union
    {
        uint8_t size;
        fileinfo* next;
    };

};

fileinfo* fileinfo_create(char* path);

void fileinfo_print(fileinfo* file);

void fileinfo_destroy(fileinfo* file);
