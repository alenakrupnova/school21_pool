#include <stdio.h>

int main() {
    double x, y;
    int scan = scanf("%lf%lf", &x, &y);
    if (scan != 2) {
        printf("n/a\n");
    }
    else {
        if (x * x + y * y <= 25) {
            printf("GOTCHA\n");
        }
        else {
            printf("MISS\n");
        }
    }
    return 0;
}