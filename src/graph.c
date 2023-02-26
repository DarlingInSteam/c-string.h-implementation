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

int **functionTomatrix(struct queue *result);

int main() {
    int flag;//флаг ошибки, который будет передоваться в функцию парсинга, чтобы при ошибке вывести n/a 
    char *input = readline_(); //вызывем функция ввода мат выражения
    struct queue *result = NULL; 

    result = shunting_yard(input, &flag); //парсим это выражение
    if (flag) { //если ошибка
        printf("n/a\n");
    } else { //иначе превращаем очередь в матрицу и выводим график
        int **matrix = functionTomatrix(result);
        output_matrix(matrix, HEIGHT, WIDTH);
        free_memory(matrix, HEIGHT);
    }

    free(input);
    free_queue(result);

    return 0;
}

int **functionTomatrix(struct queue *result) { //превращаем функцию в матрицу
    int **matrix = calloc(HEIGHT, sizeof(int *)); 

    for (int i = 0; i < HEIGHT; i++) matrix[i] = calloc(WIDTH, sizeof(int));

    for (int i = 0; i < WIDTH; i++) { //проходим по 
        int flag = 0;
        struct stack *temp = NULL;
        struct queue *current = result;

        while (current) { // проходим по очереди и смотрим какудю операцию надо провести
            if (current->data > 0) {
                temp = push(temp, current->data);
            } else {
                switch ((int)current->data) { //свич у нас проверяет значение операций (-1 -2 -3 -4 и тд)
                    double x2;
                    double x1;
                    double x;
                    case PLUS: //кейсы потерпели маленькое изменение, теперь не -1 -2 -3, а названия операций, в самих кейсах идет работа со стеком, где лежат знаения
                        x2 = temp->data;
                        temp = pop(temp); //берем из стека верхний элемент
                        x1 = temp->data; //берем из верхнего элемента значение
                        temp = pop(temp); // потом берем новый верхний элемент стека
                        temp = push(temp, x1 + x2); // и складываем их значения
                        break; //таким образом работаем и дальше во всех кейсах дальше работаем так же, как и в этом кейсе
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
                        temp = push(temp, i * 4.0 * M_PI / 79.0); //если икс, то он должен лежать от 0 до 4пи и в рамках нашего поля от 0 до 79
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
