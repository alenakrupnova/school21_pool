#include <stdio.h>

int fib(int n);

int main() {
    float n;
    int scan = scanf("%f", &n);
    if (scan == 1 && (int)n == n) {
        printf("%d\n", fib(n));
    }
    else {
        printf("n/a\n");
    }
    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}