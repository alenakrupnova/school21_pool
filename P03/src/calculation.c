#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_libs.h"
#include "rpn.h"
#include "stack.h"

double evaluate_rpn(const char *rpn, double x) {
    StackNode *stack = NULL;
    char double_buf[32];
    int pos = 0;
    int is_minus = 0;
    double res = 0.0;
    double epsilon = 1e-6;

    for (int i = 0; rpn[i] != '\0'; i++) {
        if (rpn[i] == 'x') {
            res = stack_pop(&stack);
            if (res > -epsilon && res < epsilon) {
                stack = stack_push(stack, is_minus ? -x : x);
            } else {
                stack = stack_push(stack, is_minus ? -x * res : x * res);
            }
            is_minus = 0;
        } else if (is_digit(rpn[i]) || rpn[i] == '.') {
            double_buf[pos++] = rpn[i];
            if (!is_digit(rpn[i + 1]) && rpn[i + 1] != '.') {
                double_buf[pos] = '\0';
                stack = stack_push(stack, is_minus ? -atof(double_buf) : atof(double_buf));
                pos = 0;
                is_minus = 0;
            }
        } else if (rpn[i] == '-' && (i == 0 || rpn[i - 1] == '(' || is_operator(rpn[i - 1]))) {
            is_minus = 1;
        } else if (is_operator(rpn[i]) && pos > 0) {
            double_buf[pos] = '\0';
            stack = stack_push(stack, atof(double_buf));
            pos = 0;
            is_minus = 0;
        } else {
            if (is_operator(rpn[i]) && pos > 0) {
                double_buf[pos] = '\0';
                stack = stack_push(stack, atof(double_buf));
                pos = 0;
                is_minus = 0;
            }
            // calculate(rpn, i, stack);
            if (rpn[i] == 's' || rpn[i] == 'c' || rpn[i] == 't' || rpn[i] == 'g' || rpn[i] == 'q' ||
                rpn[i] == 'l') {
                double a = stack_pop(&stack);
                switch (rpn[i]) {
                    case 's':
                        stack = stack_push(stack, sin(a));
                        break;
                    case 'c':
                        stack = stack_push(stack, cos(a));
                        break;
                    case 't':
                        stack = stack_push(stack, tan(a));
                        break;
                    case 'g':
                        stack = stack_push(stack, 1.0 / tan(a));
                        break;
                    case 'q':
                        stack = stack_push(stack, sqrt(a));
                        break;
                    case 'l':
                        stack = stack_push(stack, log(a));
                        break;
                }
            } else {
                // Для бинарных операций берем два операнда
                double b = stack_pop(&stack);
                double a = stack_pop(&stack);
                switch (rpn[i]) {
                    case '+':
                        stack = stack_push(stack, a + b);
                        break;
                    case '-':
                        stack = stack_push(stack, a - b);
                        break;
                    case '*':
                        stack = stack_push(stack, a * b);
                        break;
                    case '/':
                        stack = stack_push(stack, a / b);
                        break;
                    case '^':
                        stack = stack_push(stack, pow(a, b));
                        break;
                }
            }
        }
    }
    res = stack_pop(&stack);
    return res;
}
