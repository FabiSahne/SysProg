#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    time_t t;
    srand((unsigned int) time(&t));

    if (argc != 2)
    {
        perror("Aufruf: ./bubblesort <zahl>");
        return EINVAL;
    }

    int n = atoi(argv[1]);
    int *a = (int*)malloc(n * sizeof(int));
    if (a == NULL)
    {
        return ENOMEM;
    }

    printf("Bitte %d ganze Zahlen eingeben: ", n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) == 1)
        {
            k++;
        }

    }


    for (int i = k; i < n; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }

    for (int i = n; i > 1; --i)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }


    printf("Sortierte Zahlenfolge: \n");
    for (int m = 0; m < n; m++)
    {
        printf("%d\n", a[m]);
    }

    free(a);
    return 0;
}