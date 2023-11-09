#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void bubblesort(void *ptr, size_t count, size_t size, int (*cmp)(const void*, const void*))
{
    void* tmp = malloc(size);
    for (int i = count; i > 1; --i)
    {
        for (int j = 0; j < i - 1; ++j)
        {

            void *lhs = ((char*) ptr) + j * size;
            void *rhs = ((char*) ptr) + (j + 1) * size;

            if (cmp(lhs, rhs) > 0)
            {
                memcpy(tmp, rhs, size);
                memcpy(rhs, lhs, size);
                memcpy(lhs, tmp, size);
            }
        }
    }
    free(tmp);
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
    const int m = strlen(argv[1]) + 1;
    if (n < 1)
    {
        perror("Anzahl muss mindestens 1 sein");
        return EINVAL;
    }

    char *a = (char*)malloc(sizeof(char) * n * m);
    if (a == NULL)
    {
        return ENOMEM;
    }

    printf("Unsortiertes Array:\n");

    for (int i = 0; i < n; ++i)
    {
        int r = rand() % (n);
        sprintf(a + i * m, "%d", r);
        printf("%s ", a + i * m);
    }
    //size *= 2;
    printf("\n");


    bubblesort(a, n, m, (int (*)(const void *, const void *))strcmp);

    printf("Sortiertes Array:\n");
    char* s = (char*)malloc((sizeof(char) * n * m));
    if (s == NULL)
    {
        return ENOMEM;
    }
    strcpy(s, a);
    for (int i = 1; i < n; ++i)
    {
        if (strcmp(a + i * m, a + (i - 1) * m) == 0)
        {
            strcat(s, "*");
        }
        else
        {
            strcat(s, " ");
            strcat(s, a + i * m);
        }
    }
    printf("%s\n", s);


    free(a);
    free(s);
    return 0;
}
