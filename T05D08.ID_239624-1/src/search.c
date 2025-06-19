#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int is_even(int x);
double mean(int *a, int n);
double varience(int *a, int n);
int sigmas(int *p, int *a, int n);
int search(int *a, int n);

int main() {
    int n, arr[NMAX];
    if (input(arr, &n) == 0) {
        int result = search(arr, n);
        printf("%d", result);
    }
    return 0;
}

int input(int *a, int *n) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || *n > NMAX || *n < 1 || (ch != ' ' && ch != '\n')) {
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

int is_even(int x) { return x % 2 == 0; }

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

int sigmas(int *p, int *a, int n) {
    double m = mean(a, n);
    double var = variance(a, n);
    return (*p <= m + 3 * sqrt(var) && *p >= m - 3 * sqrt(var));
}

int search(int *a, int n) {
    double m = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        if (is_even(*p) && (*p >= m) && sigmas(p, a, n) && (*p != 0)) {
            return *p;
        }
    }
    return 0;
}