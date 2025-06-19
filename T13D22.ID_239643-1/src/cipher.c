#include <stdio.h>
#include <string.h>

int read_print(const char *path) {
    int error_empty = 0;
    int flag = 1;
    char buffer[256];
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        flag = 0;
    } else {
        if (fgetc(file) != EOF) {
            rewind(file);
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                error_empty = 1;
                printf("%s", buffer);
            }
            printf("\n");
        }
        fclose(file);
    }
    if (error_empty == 0) {
        flag = 0;
    }
    return flag;
}

int write(const char *path, const char *str) {
    int flag = 1;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        flag = 0;
    } else {
        fclose(file);
        file = fopen(path, "a");
        if (file == NULL) {
            flag = 0;
        } else {
            fprintf(file, "%s", str);
            fclose(file);
        }
    }
    return flag;
}

void encrypt() {
    char *files[] = {"ai_modules/m1.c", "ai_modules/m2.c", "ai_modules/m1.h", "ai_modules/m2.h"};
    int shift;
    scanf("%d", &shift);
    for (int i = 0; i < 4; i++) {
        int len = strlen(files[i]);
        if (files[i][len - 1] == 'h') {
            FILE *file = fopen(files[i], "w");
            fclose(file);
        } else {
            char ch;
            FILE *file = fopen(files[i], "r+");
            while ((ch = getc(file)) != EOF) {
                fseek(file, -1, SEEK_CUR);
                fputc((ch + shift), file);
                fseek(file, 0, SEEK_CUR);
            }
            fclose(file);
        }
    }
}

int main() {
    int num;
    char filename[256];
    char str[256];
    int error;
    int flag = scanf("%d", &num);
    while (flag == 1) {
        if (num == -1) {
            break;
        } else if (num == 1) {
            if (scanf("%255s", filename) != 1) {
                printf("n/a\n");
                while (getchar() != '\n');  // Очистка буфера ввода
                flag = scanf("%d", &num);
                continue;
            }
            error = read_print(filename);
            if (error == 0) {
                printf("n/a\n");
            }
        } else if (num == 2) {
            getchar();
            if (scanf("%255[^\n]", str) != 1) {
                printf("n/a\n");
                while (getchar() != '\n');  // Очистка буфера ввода
                flag = scanf("%d", &num);
                continue;
            }
            error = write(filename, str);
            if (error == 0) {
                printf("n/a\n");
            } else {
                read_print(filename);
            }
        } else if (num == 3) {
            encrypt();
        } else {
            printf("n/a\n");
        }
        flag = scanf("%d", &num);
    }
    return 0;
}