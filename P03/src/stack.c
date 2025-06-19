#include "stack.h"

#include <stdlib.h>

StackNode *stack_push(StackNode *top, double data) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->next = top;
    }
    return new_node;
}

double stack_pop(StackNode **top) {
    double res = 0.0;
    if (*top) {
        StackNode *temp = *top;
        double data = temp->data;
        *top = temp->next;
        free(temp);
        res = data;
    }
    return res;
}

int stack_is_empty(StackNode *top) {
    int res = 0;
    if (top == NULL) {
        res = 1;
    }
    return res;
}