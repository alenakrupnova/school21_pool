#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test(const char *input, size_t expected) {
    size_t res = s21_strlen(input);
    printf("INPUT: \"%s\"\n", input);
    printf("OUTPUT: %zu\n", res);
    if (res == expected) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strcmp_test(const char *input1, const char *input2, int expected) {
    int res = s21_strcmp(input1, input2);
    printf("INPUT: \"%s\" \"%s\"\n", input1, input2);
    printf("OUTPUT: %d\n", res);
    if (res == expected) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strcpy_test() {
    char dest[20] = "initial";
    const char *src = "hello";
    printf("INPUT: dest=\"initial\", src=\"%s\"\n", src);
    char *res = s21_strcpy(dest, src);
    printf("OUTPUT: dest=\"%s\"\n", res);
    if (s21_strcmp(res, src) == 0) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    char dest1[20] = "start";
    const char *src1 = "";
    printf("INPUT: dest=\"initial\", src=\"%s\"\n", src1);
    char *res1 = s21_strcpy(dest1, src1);
    printf("OUTPUT: dest=\"%s\"\n", res1);
    if (s21_strcmp(res1, src1) == 0) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    const char *src2 = "hello";
    printf("INPUT: dest=NULL, src=\"%s\"\n", src2);
    printf("OUTPUT: Error. No destination buffer\n");
    printf("FAIL\n\n");
}

void cat(char *destination, const char *src, char *expected) {
    char dest[100];
    s21_strcpy(dest, destination);
    char *res = s21_strcat(destination, src);

    printf("INPUT: \"%s\" \"%s\"\n", dest, src);
    printf("OUTPUT: \"%s\"\n", res);
    if (s21_strcmp(expected, res) == 0) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strcat_test() {
    char dest1[100] = "Cat";
    cat(dest1, "Dog", "CatDog");

    char dest2[100] = "Cat";
    cat(dest2, "", "Cat");

    char dest3[100] = "\t";
    cat(dest3, "Dog", "\tDog");
}

int main() {
#ifdef S21_STRLEN_TEST
    s21_strlen_test("hello world", 11);
    s21_strlen_test("\t", 1);
    s21_strlen_test(" ", 1);
    s21_strlen_test("\0", 0);
#elif S21_STRCMP_TEST
    s21_strcmp_test("a", "b", -1);
    s21_strcmp_test("hello", "Hello", 1);
    s21_strcmp_test("hello", "hello", 0);
    s21_strcmp_test(" ", "\t", 1);
#elif S21_STRCPY_TEST
    s21_strcpy_test();
#elif S21_STRCAT_TEST
    s21_strcat_test();
#endif
    return 0;
}