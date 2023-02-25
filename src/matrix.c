#include "matrix.h"
//выделение памяти
void alloc_memory(char ***matrix, int height, int width) {
    (*matrix) = malloc(height * sizeof(char *));
    
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = malloc(width * sizeof(char *));
    }
}
//вывод матрицы
void output_matrix(char **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", matrix[i][j]);
        }

        if (i + 1 < height) printf("\n");
    }
}
//освобождение памяти (выделена способом построчным)
void free_memory(char **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }

    free(matrix);
}
//меняется строки со столбцами
void swap(char **matrix, int loop_i, int loop_j) {
    char *temp = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = temp;
}