#ifndef MATRIX_H
#define MATRIX_H

void alloc_memory(char ***matrix, int height, int width); // выделение памяти
void output_matrix(char **matrix, int height, int width); //вывод матрицы
void free_memory(char **matrix, int height); //освобожде памяти
void swap(char **matrix, int loop_i, int loop_j); 

#endif 