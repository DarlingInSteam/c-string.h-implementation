#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void output_matrix(int **matrix, int height, int width) {
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }

        if (i - 1 > -1 ) printf("\n");
    }
}

void free_memory(int **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }

    free(matrix);
}