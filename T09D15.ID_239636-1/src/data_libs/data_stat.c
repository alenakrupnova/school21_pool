#include "data_stat.h"

double max(double *data, int n) {
    double max_i = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max_i) {
            max_i = data[i];
        }
    }
    return max_i;
}

double min(double *data, int n) {
    double min_i = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min_i) {
            min_i = data[i];
        }
    }
    return min_i;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0;
    double m = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sum / n;
}