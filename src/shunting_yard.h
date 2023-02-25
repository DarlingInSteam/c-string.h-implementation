#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#define is_operator(x) (-5 <= x && x <= -1)
#define is_operator_c(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
#define is_function(x) (-13 <= x && x <= -8)

#include <stdio.h>
#include <stdlib.h>

char *readline_();
struct queue *shunting_yard(char *input, int *flag);
int priority(int token);
int associativity(int token);

#endif