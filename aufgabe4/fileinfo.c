#include "fileinfo.h"

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/stat.h>

fileinfo* fileinfo_create(char* path)
{
    if (strlen(path) > NAME_MAX)
    {
        errno = ENAMETOOLONG;
        return NULL;
    }


    struct stat file;
    if (lstat(path, &file) != 0)
    {
        return NULL;
    }

    fileinfo* info = malloc(sizeof(fileinfo));
    info->name = path;
    if (S_ISDIR(file.st_mode))
    {
        info->type = filetype_directory;
        // TODO: not like this, wtf
        strcat(path, "/*");
        info->next = fileinfo_create(path);
        return info;
    }
    if (S_ISREG(file.st_mode))
    {
        info->type = filetype_regular;
        info->size = file.st_size;
        return info;
    }
    info->type = filetype_other;
    return info;
}

void print_regular(char* name, int size)
{
    printf("%s (regular, %d Byte)\n", name, size);
}

void print_directory(char* path, char* name, fileinfo* head)
{
    printf("%s (directory)\n", name);
}

void print_other(char* name)
{
    printf("%s (other)\n", name);
}

void fileinfo_print(fileinfo* file)
{
    if (file->type == filetype_regular)
    {
        print_regular(file->name, file->size);
    }
    else if (file->type == filetype_directory)
    {
        print_directory("", file->name, file->next);
    }
    else if (file->type == filetype_other)
    {
        print_other(file->name);
    }
}

void fileinfo_destroy(fileinfo* file)
{
    if (file->type == filetype_regular)
    {
        free(file);
    }
}
