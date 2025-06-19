#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"
#include "draw.h"
#include "my_libs.h"
#include "rpn.h"

// Самописная функция для сравнения строк
int strings_equal(const char *a, const char *b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return *a == *b;
}

// Самописная функция для вычисления длины строки
int string_length(const char *s) {
    int len = 0;
    while (*s++) len++;
    return len;
}

void test_rpn_conversion() {
    struct {
        const char *input;
        const char *expected;
    } tests[] = {{"3+4", "34+"},   {"3+4*5", "345*+"},   {"(3+4)*5", "34+5*"},
                 {"sin(x)", "xs"}, {"cos(x+1)", "x1+c"}, {"3+4*2/(1-5)^2", "342*15-2^/+"}};

    for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
        char output[256];
        parse_to_rpn(tests[i].input, output);

        if (strings_equal(output, tests[i].expected)) {
            char pass_msg[100];
            char *p = pass_msg;
            const char *msg = "Test %d PASSED: %s -> %s\n";
            while (*msg) *p++ = *msg++;
            *p = '\0';

            printf(pass_msg, i + 1, tests[i].input, output);
        } else {
            char fail_msg[100];
            char *p = fail_msg;
            const char *msg = "Test %d FAILED: expected %s, got %s\n";
            while (*msg) *p++ = *msg++;
            *p = '\0';

            printf(fail_msg, i + 1, tests[i].expected, output);
        }
    }
}

void test_evaluation() {
    struct {
        const char *rpn;
        double x;
        double expected;
        double tolerance;
    } tests[] = {
        {"34+", 0, 7, 0.001},
        {"x2*", 3, 6, 0.001},
        {"xs", 0, 0, 0.001},  // sin(0)
        {"xc", 0, 1, 0.001},  // cos(0)
        {"xq", 4, 2, 0.001}   // sqrt(4)
    };

    for (int i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
        double result = evaluate_rpn(tests[i].rpn, tests[i].x);
        double diff = result - tests[i].expected;
        if (diff < 0) diff = -diff;

        if (diff < tests[i].tolerance) {
            char pass_msg[100];
            char *p = pass_msg;
            const char *msg = "Eval test %d PASSED: %s (x=%g) -> %g\n";
            while (*msg) *p++ = *msg++;
            *p = '\0';

            printf(pass_msg, i + 1, tests[i].rpn, tests[i].x, result);
        } else {
            char fail_msg[100];
            char *p = fail_msg;
            const char *msg = "Eval test %d FAILED: expected %g, got %g\n";
            while (*msg) *p++ = *msg++;
            *p = '\0';

            printf(fail_msg, i + 1, tests[i].expected, result);
        }
    }
}

int main() {
    printf("Тест преобразования\n");
    test_rpn_conversion();

    printf("\nТест сравнения\n");
    test_evaluation();

    return 0;
}