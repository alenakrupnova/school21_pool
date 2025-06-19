#include <stdio.h>
#include <stdlib.h>

int *inputArray(int *size);
void bubble_sort(int *array, int size);
void output(int *array, int size);

int main() {
    int n;
    int *arr = inputArray(&n);
    if (arr != NULL) {
        bubble_sort(arr, n);
        output(arr, n);
    }
    free(arr);
    return 0;
}

int *inputArray(int *size) {
    if (scanf("%d", size) != 1 || *size <= 0) {
        printf("n/a");
        return NULL;
    }
    int *arr = (int *)calloc(*size, sizeof(int));
    if (arr == NULL) {
        printf("n/a");
        return NULL;
    }
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            printf("n/a");
            return NULL;
        }
    }
    return arr;
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void output(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}