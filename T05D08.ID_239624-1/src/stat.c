#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {  // data = &data[0] = адрес нулевого элемента массива
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

int input(int *a, int *n) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || (*n < 1) || (*n > NMAX) || (ch != ' ' && ch != '\n')) {
        printf("n/a");
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            printf("n/a");
            return 1;
        }
    }
    if (ch != '\n') {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a) {
            printf("%d", *p);
        } else {
            printf(" %d", *p);
        }
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(int *a, int n) {
    int sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    return (double)sum / n;
}

double variance(int *a, int n) {
    double var_sum = 0;
    double m = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        var_sum += (*p - m) * (*p - m);
    }
    return var_sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}