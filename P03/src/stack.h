#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    double data;
    struct StackNode *next;
} StackNode;

StackNode *stack_push(StackNode *top, double data);
double stack_pop(StackNode **top);
int stack_is_empty(StackNode *top);

#endif