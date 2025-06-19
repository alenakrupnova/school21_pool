#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input(double **data, int *n) {
    if (scanf("%d", n) != 1 || *n < 1) {
        return;
    }
    *data = (double *)malloc(*n * sizeof(double));
    if (*data == NULL) {
        free(*data);
        return;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", &(*data)[i]) != 1) {
            free(*data);
            return;
        }
    }
}

void output(double **data, int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%.2lf", (*data)[i]);
        if (i != *n - 1) {
            printf(" ");
        }
    }
    // if (*data != NULL) {
    //     free(*data);
    // }
}
