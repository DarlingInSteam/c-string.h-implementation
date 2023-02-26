#ifndef SRC_QUEUE_H
#define SRC_QUEUE_H

#include <stdlib.h>

struct queue { //структура очереди
    int data; //значение
    struct queue *next;// ссылка на след элемент
};

struct queue *push_queue(struct queue *root, int data);
void free_queue(struct queue *root);

#endif