#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) { // data = &data[0] = адрес нулевого элемента массива
        squaring(data, n);
        output(data, n);
    }
    
    return 0;
}

int input(int *a, int *n) {
    char symbol;
    if (scanf("%d%c", n, &symbol) != 2 || (*n > NMAX) || (*n < 1) || (symbol != ' ' && symbol != '\n')) {
        printf("n/a");
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &symbol) != 2 || (symbol != ' ' && symbol != '\n')) {
            printf("n/a");
            return 1;
        }
    }
    if (symbol != '\n') {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {

        if (p == a) {
            printf("%d", *p);
        }
        else {
            printf(" %d", *p);
        }
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}