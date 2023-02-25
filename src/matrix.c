#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void alloc_memory(char ***matrix, int height, int width) {
    (*matrix) = malloc(height * sizeof(char *));
    
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = malloc(width * sizeof(char *));
    }
}

void output_matrix(char **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", matrix[i][j]);
        }

        if (i + 1 < height) printf("\n");
    }
}

void free_memory(int **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

void swap(char **matrix, int loop_i, int loop_j) {
    char *temp = matrix[loop_i];
    matrix[loop_i] = matrix[loop_j];
    matrix[loop_j] = temp;
}