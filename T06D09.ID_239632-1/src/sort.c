#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main() {
    int arr[NMAX];
    if (input(arr) == 0) {
        sort(arr);
        output(arr);
    }
    return 0;
}

int input(int *a) {
    char ch;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d%c", p, &ch) != 2 || (ch != ' ' && ch != '\n')) {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}

void sort(int *a) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (i == 0) {
            printf("%d", a[i]);
        } else {
            printf(" %d", a[i]);
        }
    }
}