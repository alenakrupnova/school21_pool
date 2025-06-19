#include <math.h>
#include <stdio.h>

int celoe(int a, int b);
int ostatok(int a, int b);
int is_prime(int a);
int max_prime_del(int a);

int main() {
    int a;
    char check;
    int scan = scanf("%d%c", &a, &check);
    if (a < 0) a = -a;
    
    int res = max_prime_del(a);
    if (scan == 2 && check == '\n') {
        printf("%d\n", res);
    } else {
        printf("n/a\n");
    }
    return 0;
}

// целочисленное деление
int celoe(int a, int b) {
    int q = 0;
    while (a >= b) {
        a -= b;
        q += 1;
    }
    return q;
}

// остаток от деления
int ostatok(int a, int b) {
    int q = celoe(a, b);
    return a - b * q;
}

// проверка на простоту
int is_prime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (ostatok(a, i) == 0) {
            return 1;
        }
    }
    return 0;
}

// наибольший простой делитель
int max_prime_del(int a) {
    int max = 1;
    for (int i = 2; i <= a; i++) {
        if (ostatok(a, i) == 0 && is_prime(i) == 0) {
            max = i;
        }
    }
    return max;
}