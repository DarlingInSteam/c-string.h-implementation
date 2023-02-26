#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
//выводим матрицу
void output_matrix(int **matrix, int height, int width) {
    for (int i = height - 1; i >= 0; i--) { //начинаем сверху, потому что значения от 1 до -1
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == 1) { //если ячейка матрицы ровна 1, то тут есть значение
                printf("*");
            } else {
                printf("."); //если там любое другое значение, то рисуем точку
            }
        }

        if (i - 1 > -1) printf("\n"); //ну и не забываем отступать строку 
    }
}

void free_memory(int **matrix, int height) { //тут просто очистка матрицы, так как наша матрица динамически выделенная 
    for (int i = 0; i < height; i++) {
        free(matrix[i]); 
    }

    free(matrix);
}