#include <stdio.h>
#define LEN 100
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int input(int *array, int *len);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
// void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void output(int *buffer, int length);

int main() {
    int arr[LEN], len, arr2[LEN], len2, arrsum[LEN + 1], lensum;
    if (!input(arr, &len) && !input(arr2, &len2)) {
        sum(arr, len, arr2, len2, arrsum, &lensum);
        output(arrsum, lensum);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *array, int *len) {
    *len = 0;
    int flag = 0;
    int scan = scanf("%d", &array[*len]);
    int oth = getchar();
    if (scan == 1 && (array[*len] >= 0 && array[*len] <= 9) && (oth == 10 || oth == 32 || oth == EOF)) {
        while (oth != 10 && oth != EOF && flag == 0) {  // пока не Enter или не конец файла
            (*len)++;
            if (scanf("%d", &array[*len]) == 1 && (array[*len] >= 0 && array[*len] <= 9)) {
                oth = getchar();
            } else {
                flag = 1;
            }
        }
    } else {
        flag = 1;
    }
    return flag;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *res_length) {
    int max_len = MAX(len1, len2);
    int ost = 0;
    *res_length = 0;
    for (int i = len1 - 1, j = len2 - 1, k = max_len; k >= 0; i--, j--, k--) {
        int digit1, digit2;
        if (i >= 0) {
            digit1 = buff1[i];
        } else {
            digit1 = 0;
        }
        if (j >= 0) {
            digit2 = buff2[j];
        } else {
            digit2 = 0;
        }
        int total = digit1 + digit2 + ost;
        result[k] = total % 10;
        ost = total / 10;

        if (k == 0 && ost > 0) {
            result[0] = ost;
            *res_length = max_len + 1;
        } else {
            *res_length = max_len;
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