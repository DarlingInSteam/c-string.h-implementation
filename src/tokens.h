#ifndef TOKENS_H
#define TOKENS_H
#define is_operator(x) (-5 <= x && x <= -1)
#define is_operator_c(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
#define is_function(x) (-13 <= x && x <= -8)

int *read_tokens(char *input, int *amount_tokens);

#endif