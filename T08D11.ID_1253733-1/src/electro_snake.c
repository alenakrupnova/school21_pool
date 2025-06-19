#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix, **result;
    int n,m;

    input(matrix, &n, &m);
    
    sort_vertical(matrix, n, m, result);
    output(result);
    
    sort_horizontal(matrix, n, m, result);
    output(result);
}

void input(int **matrix, int *n, int *m) {
    char c1, c2;
    if (scanf("%d%c%d%c", n, &c1, m, &c2) != 4 || (c1 != ' ' && c1 != '\n') || (c2 != ' ' && c2 != '\n') || (*n < 0) || (*m < 0)) {
        printf("n/a");
        return 0;
    }
    const int N = *n, M = *m;
    matrix = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(M * sizeof(int));
    }
    int value, flag = 1;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d%c", &value, &c) != 2 || (c != ' ' && c != '\n')) {
                printf("n/a");
                return 0;
            }
            else {
                matrix[i][j] = value;
            }
        }
    }
    return 1;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int length = 0;
    int * temp_array = (int*) malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp_array[length] = matrix[j][i];
            length++;
        }
    }
    for (int i = 0; i < )
}