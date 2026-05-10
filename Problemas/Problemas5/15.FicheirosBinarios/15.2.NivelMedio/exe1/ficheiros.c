#include "ficheiros.h"

#include <stdio.h>
#include <stdlib.h>

static int cmp_long(const void *a, const void *b)
{
    long int x = *(const long int *)a;
    long int y = *(const long int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int ordenar_ficheiro_long(const char *origem, const char *destino)
{
    FILE *fi = fopen(origem, "rb");
    FILE *fo;
    long int *arr;
    long n;

    if (fi == NULL) {
        return 0;
    }

    fseek(fi, 0, SEEK_END);
    n = ftell(fi) / (long)sizeof(long int);
    rewind(fi);

    if (n <= 0) {
        fclose(fi);
        return 0;
    }

    arr = (long int *)malloc((size_t)n * sizeof(long int));
    if (arr == NULL) {
        fclose(fi);
        return 0;
    }

    fread(arr, sizeof(long int), (size_t)n, fi);
    fclose(fi);

    qsort(arr, (size_t)n, sizeof(long int), cmp_long);

    fo = fopen(destino, "wb");
    if (fo == NULL) {
        free(arr);
        return 0;
    }

    fwrite(arr, sizeof(long int), (size_t)n, fo);
    fclose(fo);
    free(arr);
    return 1;
}
