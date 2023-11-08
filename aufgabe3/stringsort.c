#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void bubblesort(char** a, int n)
{
    for (int i = n; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                char* tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    time_t t;
    srand((unsigned int) time(&t));

    if (argc != 2)
    {
        perror("Aufruf ./stringsort <anzahl>");
        return EINVAL;
    }

    const int n = atoi(argv[1]);
    if (n < 1)
    {
        perror("Anzahl muss mindestens 1 sein");
        return EINVAL;
    }

    char **a = (char**)malloc(sizeof(char*)*n);
    if (a == NULL)
    {
        return ENOMEM;
    }

    printf("Unsortiertes Array:\n");
    
    int size = 0;
    for (int i = 0; i < n; ++i)
    {
        int r = rand()%(n);
        a[i] = (char*)malloc(sizeof(char)*strlen(argv[1]+1));
        size += sprintf(a[i], "%d", r);
        printf("%s ", a[i]);
    }
    size *= 2;
    printf("\n");


    bubblesort(a, n);

    printf("Sortiertes Array:\n");
    char* s = (char*)malloc(sizeof(char)*size);
    if (s == NULL)
    {
        return ENOMEM;
    }
    strcat(s, a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a[i], a[i - 1]) == 0)
        {
            strcat(s, "*");
        } 
        else
        {
            strcat(s, " ");
            strcat(s, a[i]);
        }
    }
    printf("%s\n", s);


    free(a);
    free(s);
    return 0;
}
