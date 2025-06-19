#include <stdio.h>

void swap(int *a, int *b);
void quick_sort(int *a, int first, int last);
int input(int *buffer, int *length);
void output(int *buffer, int *length);
void heapSort(int *buffer, int n);
void heapify(int *a, int n, int i);

int main() {
    int n = 10, arr[n];
    if (!input(arr, &n)) {
        quick_sort(arr, 0, n - 1);
        output(arr, &n);
        printf("\n");
        heapSort(arr, n);
        output(arr, &n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    char ch;
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &ch) != 2 || (ch != ' ' && i < *length - 1) ||
            (ch != '\n' && i == *length - 1)) {
            return 1;
        }
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right) {
                swap(a + left, a + right);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void output(int *buffer, int *length) {
    for (int i = 0; i < *length; i++) {
        if (i == 0) {
            printf("%d", buffer[i]);
        } else {
            printf(" %d", buffer[i]);
        }
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;  // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;   // Левый потомок
    int right = 2 * i + 2;  // Правый потомок

    // Если левый потомок больше корня
    if (left < n && a[left] > a[largest]) largest = left;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (right < n && a[right] > a[largest]) largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        // Меняем местами корень и наибольший элемент
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Рекурсивно преобразуем затронутое поддерево
        heapify(a, n, largest);
    }
}

// Основная функция для пирамидальной сортировки
void heapSort(int *buffer, int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--) heapify(buffer, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        int temp = buffer[0];
        buffer[0] = buffer[i];
        buffer[i] = temp;

        // Вызываем heapify на уменьшенной куче
        heapify(buffer, i, 0);
    }
}