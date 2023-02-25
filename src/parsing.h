#ifndef PARSING_H
#define PARSING_H

#include <stdlib.h>

char *input_math_expression();
int validation_input(char *input);
int is_num(char ch);
int is_func(char ch);
int is_math_symbol(char ch);

#endif