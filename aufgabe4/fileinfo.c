#include "fileinfo.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/stat.h>

fileinfo* fileinfo_create(char* path){

    fileinfo* info = malloc(sizeof(fileinfo));


    if (strlen(path) > NAME_MAX) {
        errno = ENAMETOOLONG;
        return NULL;
    }

    struct stat file;
    if (lstat(path, &file) != 0)
    {
        return NULL;
    }
    if (S_ISDIR(file.st_mode))
    {
        info->type = filetype_directory;
        strcat(path, "/*");
        info->head = fileinfo_create(path);
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

void fileinfo_print(fileinfo* file)
{
    if (file->type == filetype_regular)
    {
        print_regular()
    }
}

void fileinfo_destroy(fileinfo* file);

