#include "rpn.h"

#include "my_libs.h"
#include "stack.h"
#include "stdio.h"

int get_priority(char op);

void parse_to_rpn(const char *input, char *output) {
    StackNode *stack = NULL;
    int out_pos = 0;
    int i = 0;

    while (input[i] != '\0') {
        if (is_space(input[i])) {
            i++;
        } else if (is_digit(input[i]) || input[i] == 'x' || input[i] == '.') {
            output[out_pos++] = input[i++];
        } else if (input[i] == '(') {
            stack = stack_push(stack, input[i++]);
        } else if (input[i] == ')') {
            while (!stack_is_empty(stack) && stack->data != '(') {
                output[out_pos++] = stack_pop(&stack);
            }
            stack_pop(&stack);
            i++;
        } else if (check_func(input, i, "sin")) {
            stack = stack_push(stack, 's');
            i += 3;
        } else if (check_func(input, i, "cos")) {
            stack = stack_push(stack, 'c');
            i += 3;
        } else if (check_func(input, i, "tan")) {
            stack = stack_push(stack, 't');
            i += 3;
        } else if (check_func(input, i, "ctg")) {
            stack = stack_push(stack, 'g');
            i += 3;
        } else if (check_func(input, i, "sqrt")) {
            stack = stack_push(stack, 'q');
            i += 4;
        } else if (check_func(input, i, "ln")) {
            stack = stack_push(stack, 'l');
            i += 2;
        } else {
            while (!stack_is_empty(stack) && get_priority((char)stack->data) >= get_priority(input[i])) {
                output[out_pos++] = stack_pop(&stack);
            }
            stack = stack_push(stack, input[i++]);
        }
    }

    while (!stack_is_empty(stack)) {
        output[out_pos++] = stack_pop(&stack);
    }

    output[out_pos] = '\0';
}

int get_priority(char op) {
    int res = 0;
    if (op == '+' || op == '-') {
        res = 1;
    } else if (op == '*' || op == '/') {
        res = 2;
    } else if (op == '^') {
        res = 3;
    } else if (op == 's' || op == 'c' || op == 't' || op == 'g' || op == 'q' || op == 'l') {
        res = 4;
    }
    return res;
}