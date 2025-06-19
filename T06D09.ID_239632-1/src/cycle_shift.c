#include <stdio.h>
#define NMAX 10
int input(int *array, int *length, int *number);
void reverse(int *array, int start, int end);
void rotate_left(int *array, int length, int number);
void output(int *array, int *length);

int main() {
    int n, arr[NMAX], c;
    if (input(arr, &n, &c) == 0) {
        rotate_left(arr, n, c);
        output(arr, &n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *array, int *length, int *number) {
    char ch;
    if (scanf("%d%c", length, &ch) != 2 || (*length < 1 || *length > NMAX) || (ch != ' ' && ch != '\n')) {
        return 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &array[i], &ch) != 2 || (ch != ' ' && ch != '\n')) {
            return 1;
        }
    }
    if (scanf("%d%c", number, &ch) != 2 || ch != '\n') {
        return 1;
    }
    return 0;
}

void reverse(int *array, int start, int end) {
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void rotate_left(int *array, int length, int number) {
    number = number % length;
    if (number < 0) {
        number += length;
    }

    reverse(array, 0, number - 1);
    reverse(array, number, length - 1);
    reverse(array, 0, length - 1);
}

void output(int *array, int *length) {
    for (int i = 0; i < *length; i++) {
        if (i == 0) {
            printf("%d", array[i]);
        } else {
            printf(" %d", array[i]);
        }
    }
}