#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

void modes(int *n);
int input_matrix_size(int *str, int *col);
int input_matrix_static(int (*matrix)[NMAX], int str, int col);
void output_static(int (*matrix)[NMAX], int str, int col);
void static_matrix();
void create_dyn1(int str, int col);
void create_dyn2(int str, int col);
void create_dyn3(int str, int col);
void dynamic1_matrix();
void dynamic2_matrix();
void dynamic3_matrix();

int main() {
    int n;
    modes(&n);
    return 0;
}

int input_matrix_size(int *str, int *col) {
    char ch1, ch2;
    if (scanf("%d%c%d%c", str, &ch1, col, &ch2) != 4 || (ch1 != ' ' && ch1 != '\n') ||
        (ch2 != ' ' && ch2 != '\n')) {
        return 0;
    }
    return (*str <= NMAX && *col <= NMAX && *str > 0 && *col > 0);
}

int input_size_dyn(int *str, int *col) {
    char ch1, ch2;
    if (scanf("%d%c%d%c", str, &ch1, col, &ch2) != 4 || (ch1 != ' ' && ch1 != '\n') ||
        (ch2 != ' ' && ch2 != '\n')) {
        return 0;
    }
    return (*str > 0 && *col > 0);
}

void create_dyn1(int str, int col) {
    const int M = str, N = col;
    int **array = malloc(M * sizeof(int *) + M * N * sizeof(int));
    int *ptr = (int *)(array + M);
    for (int i = 0; i < M; i++) {
        array[i] = ptr + N * i;
    }
    int value, flag = 1;
    char c;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if (res1 != 2 || (c != ' ' && c != '\n')) {
                flag = 0;
                printf("n/a");
                break;
            } else {
                array[i][j] = value;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", array[i][j]);
                if (j != N - 1) {
                    printf(" ");
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
    }
    free(array);
}

void create_dyn2(int str, int col) {
    const int M = str, N = col;
    int **array = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        array[i] = malloc(N * sizeof(int));
    }
    int value, flag = 1;
    char c;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if (res1 != 2 || (c != ' ' && c != '\n')) {
                flag = 0;
                printf("n/a");
                break;
            } else {
                array[i][j] = value;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", array[i][j]);
                if (j != N - 1) {
                    printf(" ");
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
        for (int i = 0; i < M; i++) {
            free(array[i]);
        }
    }
    free(array);
}

void create_dyn3(int str, int col) {
    const int M = str, N = col;
    int **pointer_array = malloc(M * sizeof(int *));
    int *values_array = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++) {
        pointer_array[i] = values_array + N * i;
    }
    int value, flag = 1;
    char c;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int res1 = scanf("%d%c", &value, &c);
            if (res1 != 2 || (c != ' ' && c != '\n')) {
                flag = 0;
                printf("n/a");
                break;
            } else {
                pointer_array[i][j] = value;
            }
        }
    }
    if (flag) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", pointer_array[i][j]);
                if (j != N - 1) {
                    printf(" ");
                }
            }
            if (i != M - 1) {
                printf("\n");
            }
        }
    }
    free(values_array);
    free(pointer_array);
}

int input_matrix_static(int (*matrix)[NMAX], int str, int col) {
    char ch;
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            if (scanf("%d%c", &matrix[i][j], &ch) != 2 || (ch != ' ' && ch != '\n')) {
                return 0;
            }
        }
    }
    return 1;
}

void output_static(int (*matrix)[NMAX], int str, int col) {
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col - 1) {
                printf(" ");
            }
        }
        if (i != str - 1) {
            printf("\n");
        }
    }
}

void static_matrix() {
    int str, col, flag = 0;
    int matrix[NMAX][NMAX];
    if (!input_matrix_size(&str, &col)) {
        flag = 1;
    } else if (!input_matrix_static(matrix, str, col)) {
        flag = 1;
    }
    if (flag == 0) {
        output_static(matrix, str, col);
    } else {
        printf("n/a");
    }
}

void dynamic1_matrix() {
    int str, col;
    if (input_size_dyn(&str, &col)) {
        create_dyn1(str, col);
    } else {
        printf("n/a");
    }
}

void dynamic2_matrix() {
    int str, col;
    if (input_size_dyn(&str, &col)) {
        create_dyn2(str, col);
    } else {
        printf("n/a");
    }
}

void dynamic3_matrix() {
    int str, col;
    if (input_size_dyn(&str, &col)) {
        create_dyn3(str, col);
    } else {
        printf("n/a");
    }
}

void modes(int *n) {
    char ch;
    if (scanf("%d%c", n, &ch) != 2 || *n < 1 || *n > 4 || ch != '\n') {
        printf("n/a");
    } else if (*n == 1) {
        static_matrix();
    } else if (*n == 2) {
        dynamic1_matrix();
    } else if (*n == 3) {
        dynamic2_matrix();
    } else {
        dynamic3_matrix();
    }
}