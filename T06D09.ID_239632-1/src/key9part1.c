#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
void find_numbers(int *buffer, int length, int number, int *numbers, int *new_length);

int main() {
    int n, arr[NMAX], arr_new[NMAX], new_len;
    if (input(arr, &n) == 0) {
        int summ = sum_numbers(arr, n);
        if (summ == 0) {
            printf("n/a");
        } else {
            printf("%d\n", summ);
            find_numbers(arr, n, summ, arr_new, &new_len);
            output(arr_new, new_len);
        }

    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    char ch;
    if (scanf("%d%c", length, &ch) != 2 || (*length < 1) || (*length > NMAX) || (ch != ' ' && ch != '\n')) {
        return 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &ch) != 2 || (ch != ' ' && i < *length - 1) ||
            (ch != '\n' && i == *length - 1)) {
            return 1;
        }
    }
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

void find_numbers(int *buffer, int length, int number, int *numbers, int *new_length) {
    *new_length = 0;  // Кол-во элементов нового массива
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[*new_length] = buffer[i];
            (*new_length)++;
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            printf("%d", buffer[i]);
        } else {
            printf(" %d", buffer[i]);
        }
    }
}