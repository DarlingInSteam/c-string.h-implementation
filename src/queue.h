#ifndef SRC_QUEUE_H
#define SRC_QUEUE_H

#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

struct queue *push_queue(struct queue *root, int data);
void free_queue(struct queue* root);

#endif 