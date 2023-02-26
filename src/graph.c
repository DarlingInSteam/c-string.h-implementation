#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "matrix.h"
#include "queue.h"
#include "shunting_yard.h"
#include "stack.h"

#define HEIGHT 25
#define WIDTH 80

int **function2matrix(struct queue *result);

int main() {
    int flag;
    char *input = readline_();
    struct queue *result = NULL;

    result = shunting_yard(input, &flag);
    if (flag) {
        printf("n/a\n");
    } else {
        int **matrix = function2matrix(result);
        output_matrix(matrix, HEIGHT, WIDTH);
        free_memory(matrix, HEIGHT);
    }

    free(input);
    free_queue(result);

    return 0;
}

int **function2matrix(struct queue *result) {
    int **matrix = calloc(HEIGHT, sizeof(int *));

    for (int i = 0; i < HEIGHT; i++) matrix[i] = calloc(WIDTH, sizeof(int));

    for (int i = 0; i < WIDTH; i++) {
        int flag = 0;
        struct stack *temp = NULL;
        struct queue *current = result;

        while (current) {
            if (current->data > 0) {
                temp = push(temp, current->data);
            } else {
                switch ((int)current->data) {
                    double x2;
                    double x1;
                    double x;
                    case PLUS:
                        x2 = temp->data;
                        temp = pop(temp);
                        x1 = temp->data;
                        temp = pop(temp);
                        temp = push(temp, x1 + x2);
                        break;
                    case MINUS_B:
                        x = temp->data;
                        temp = pop(temp);
                        temp = push(temp, -x);
                        break;
                    case MINUS_U:
                        x2 = temp->data;
                        temp = pop(temp);
                        x1 = temp->data;
                        temp = pop(temp);
                        temp = push(temp, x1 - x2);
                        break;
                    case MUL:
                        x2 = temp->data;
                        temp = pop(temp);
                        x1 = temp->data;
                        temp = pop(temp);
                        temp = push(temp, x1 * x2);
                        break;
                    case DIF:
                        x2 = temp->data;
                        temp = pop(temp);
                        x1 = temp->data;
                        temp = pop(temp);
                        if (x2)
                            temp = push(temp, x1 / x2);
                        else
                            flag = 1;
                        break;
                    case SIN:
                        x = temp->data;
                        temp = pop(temp);
                        temp = push(temp, sin(x));
                        break;
                    case COS:
                        x = temp->data;
                        temp = pop(temp);
                        temp = push(temp, cos(x));
                        break;
                    case TAN:
                        x = temp->data;
                        temp = pop(temp);
                        if (cos(x))
                            temp = push(temp, tan(x));
                        else
                            flag = 1;
                        break;
                    case CTG:
                        x = temp->data;
                        temp = pop(temp);
                        if (sin(x))
                            temp = push(temp, cos(x) / sin(x));
                        else
                            flag = 1;
                        break;
                    case SQRT:
                        x = temp->data;
                        temp = pop(temp);
                        if (x)
                            temp = push(temp, sqrt(x));
                        else
                            flag = 1;
                        break;
                    case LN:
                        x = temp->data;
                        temp = pop(temp);
                        if (x)
                            temp = push(temp, log(x));
                        else
                            flag = 1;
                        break;
                    case X:
                        temp = push(temp, i * 4.0 * M_PI / 79.0);
                        break;
                }



            }
            if (flag) break;
            current = current->next;
        }

        if (!flag) {
            if (0 <= (int)round(temp->data * 12.0) + 12 && (int)round(temp->data * 12.0) + 12 <= 24)
                matrix[(int)round(temp->data * 12.0) + 12][i] = 1;
        }

        free_stack(temp);
    }

    return matrix;
}
