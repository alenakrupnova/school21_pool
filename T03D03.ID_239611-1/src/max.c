#include <stdio.h>

int max(int a, int b);

int main() {
    double x, y;
    
    int some = scanf("%lf%lf", &x, &y);
    if (some == 3 && (int)x == x && (int)y == y) {
        printf("%d", max(x, y));
    } else {
        printf("n/a");
    }
    return 0;
}

int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}


