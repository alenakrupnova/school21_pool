#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"
#include "draw.h"
#include "my_libs.h"
#include "rpn.h"

typedef struct StackNode {
    char data;
    struct StackNode *next;
} StackNode;

int is_digit(char c);
int is_space(char c);
int get_precedence(char op);
void init_graph(char graph[HEIGHT][WIDTH]);
void draw_graph(char graph[HEIGHT][WIDTH]);

void parse_to_rpn(const char *input, char *output);
double evaluate_rpn(const char *rpn, double x);

StackNode *stack_push(StackNode *top, char data);
char stack_pop(StackNode **top);
int stack_is_empty(StackNode *top);

int main() {
    char input[100];
    char rpn[100];
    char graph[HEIGHT][WIDTH];

    init_graph(graph);

    printf("Введите функцию (используйте 'x' как переменную): ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);

    parse_to_rpn(input, rpn);

    for (int col = 0; col < WIDTH; col++) {
        double x = X_MIN + (X_MAX - X_MIN) * col / (WIDTH - 1);
        double y = evaluate_rpn(rpn, x);

        int row = (int)round((1 - y) * (HEIGHT - 1) / 2);

        if (row >= 0 && row < HEIGHT) {
            graph[row][col] = '*';
        }
    }

    draw_graph(graph);

    return 0;
}