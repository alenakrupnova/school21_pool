#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int prod(int a, int b);
int quo(int a, int b);

int main() {
    int x, y;
    char ost;
    int some = scanf("%d%d%c", &x, &y, &ost);
    if (some == 3 && ost == '\n') {
        if (y == 0) {
            printf("%d %d %d n/a\n", sum(x, y), diff(x, y), prod(x, y));
        } else {
            printf("%d %d %d %d\n", sum(x, y), diff(x, y), prod(x, y), quo(x, y));
        }
    } else {
        printf("n/a\n");
    }
    return 0;
}

int sum(int a, int b) { return a + b; }

int diff(int a, int b) { return a - b; }

int prod(int a, int b) { return a * b; }

int quo(int a, int b) { return a / b; }