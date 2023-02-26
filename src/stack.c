#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init(double data) { //инициализация стека
    struct stack *elements = malloc(sizeof(struct stack));

    elements->data = data;
    elements->next = NULL;

    return elements;
}

struct stack *push(struct stack *root, double data) { //добавляем элемент стека на верхушку
    struct stack *new = init(data);

    if (root) new->next = root;

    return new;
}

struct stack *pop(struct stack *root) { //забираем элемент стека с верхушки и удаляем его
    if (root) {
        struct stack *next = root->next;
        free(root);
        root = next;
    }

    return root;
}

void free_stack(struct stack *root) { //очищаем стек
    struct stack *current = root, *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(current);
}