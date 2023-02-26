#ifndef STACK_H
#define STACK_H

struct stack { //структура стека
    double data;
    struct stack *next;
};

struct stack *push(struct stack *root, double data);
struct stack *pop(struct stack *root);
void free_stack(struct stack *root);

#endif