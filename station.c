/* station.c - Natalia Robertson */
#include <stdio.h>
#include <stdlib.h>
#include "station.h"

int *make_log(int n)
{
    if (n <= 0) {
        return NULL;
    }
    return malloc((size_t)n * sizeof(int));
}

int *grow_log(int *log, int old_n, int new_n)
{
    if (new_n <= old_n) {
        return log;
    }
    if (log == NULL) {
        return make_log(new_n);
    }
    int *tmp = realloc(log, (size_t)new_n * sizeof *tmp);
    return tmp;  
}

int *append_reading(int *log, int *n, int value)
{
    if (n == NULL || (log == NULL && *n != 0)) {
        return NULL;
    }
    int *tmp = grow_log(log, *n, *n + 1);
    if (tmp == NULL) {
        return NULL;      /* unchanged */
    }
    tmp[*n] = value;
    *n += 1;
    return tmp;
}

void free_log(int **log)
{
    if (log == NULL) {
        return;
    }
    free(*log);
    *log = NULL;
}
void print_log(const int *log, int n)
{
    if (log == NULL || n <= 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", log[i]);
    }
    printf("\n");
}

int max_reading(const int *log, int n)
{
    if (log == NULL || n <= 0) {
        return 0;
    }
    int max = log[0];
    for (int i = 1; i < n; i++) {
        if (log[i] > max) {
            max = log[i];
        }
    }
    return max;
}
