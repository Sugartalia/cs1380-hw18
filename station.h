#ifndef STATION_H
#define STATION_H

int *make_log(int n);
void print_log(const int *log, int n);
int max_reading(const int *log, int n);
int *grow_log(int *log, int old_n, int new_n);
int *append_reading(int *log, int *n, int value);
void free_log(int **log);

#endif
