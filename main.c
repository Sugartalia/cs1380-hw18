/* main.c - Natalia Robertson */
#include <stdio.h>
#include "station.h"

int main(void)
{
    int n = 3;
    int *log = make_log(n);
    int *bigger = NULL;
    int *next = NULL;

    if (log == NULL) {
        printf("make_log failed\n");
        return 1;
    }

    
    log[0] = 68;
    log[1] = 71;
    log[2] = 64;
    printf("start n=%d: ", n);
    print_log(log, n);

    
    bigger = grow_log(log, n, 6);
    if (bigger == NULL) {
        printf("grow_log failed\n");
        free_log(&log);
        return 1;
    }
    log = bigger;
    n = 6;
    log[3] = 72;
    log[4] = 70;
    log[5] = 67;
    printf("after grow n=%d: ", n);
    print_log(log, n);
    printf("max = %d\n", max_reading(log, n));

    /* Step 3: append two readings */
    next = append_reading(log, &n, 69);
    if (next == NULL) {
        printf("append_reading failed\n");
        free_log(&log);
        return 1;
    }
    log = next;

    next = append_reading(log, &n, 65);
    if (next == NULL) {
        printf("append_reading failed\n");
        free_log(&log);
        return 1;
    }
    log = next;

    printf("after append n=%d: ", n);
    print_log(log, n);
    printf("max = %d\n", max_reading(log, n));

    
    print_log(NULL, 3);
    printf("max_reading(NULL, 3) = %d\n", max_reading(NULL, 3));

    
    free_log(&log);
    if (log == NULL) {
        printf("after free_log, pointer is NULL\n");
    } else {
        printf("after free_log, pointer is NOT NULL (bug!)\n");
    }

    
    free_log(&log);

    return 0;
}
