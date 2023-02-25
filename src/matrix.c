#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void output_matrix(int **matrix, int height, int width) {
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