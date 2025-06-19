#include "s21_string.h"

int s21_strlen(const char *str) {
    int len = 0;
    for (; *(str + len) != 0; len++);
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
    for (; *str1 != 0 && *str1 == *str2; str1++, str2++);
    if ((*str1 - *str2) < 0) {
        res = -1;
    } else if ((*str1 - *str2) > 0) {
        res = 1;
    }
    return res;
}

char *s21_strcpy(char *dest, const char *source) {
    char *current = dest;
    while (*source != '\0') {
        *current = *source;
        source++;
        current++;
    }
    *current = '\0';
    return dest;
}

char *s21_strcat(char *dest, const char *src) {
    int len = s21_strlen(dest);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + s21_strlen(src)] = '\0';
    return dest;
}