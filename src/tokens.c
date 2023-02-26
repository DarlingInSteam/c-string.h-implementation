#include "tokens.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"

int *read_tokens(char *input, int *amount_tokens) { //разбиваем строку ввода на токены
    int len = (int)strlen(input), flag = 0; // тут длина строки ввода и флаг
    int *tokens = NULL, *tmp = NULL; //токен и темп для токена

    *amount_tokens = 0; //количество токенов

    for (int i = 0; i < len;) {
        if (len - i >= 1 && is_operator_c(input[i])) { //есть ли в строке ввода хоть какая-то операция
            tmp = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            if (tmp != NULL) {
                tokens = tmp;
            } else {
                flag = 1;
                break;
            }

            switch (input[i]) { //свич работает с каждым элементом строки ввода
                case '+': // если у нас элемень строки равен плюсу или - и тд то ему присваивается значение (значения можно посмотреть в define.h)
                    tokens[*amount_tokens] = PLUS;
                    break;
                case '-':
                    if (tokens[*amount_tokens - 1] > -1)
                        tokens[*amount_tokens] = MINUS_U;
                    else
                        tokens[*amount_tokens] = MINUS_B;
                    break;
                case '*':
                    tokens[*amount_tokens] = MUL;
                    break;
                case '/':
                    tokens[*amount_tokens] = DIF;
                    break;
                case '(':
                    tokens[*amount_tokens] = OPEN_SKOB;
                    break;
                case ')':
                    tokens[*amount_tokens] = CLOSE_SKOB;
                    break;
            }

            (*amount_tokens)++;
            i += 1;
        } else if ('0' <= input[i] && input[i] <= '9') { //если не функция а число то переводим его из строки в число и добавляем в виде числа а не строки
            int digit = 0;

            while ('0' <= input[i] && input[i] <= '9' && i < len) {
                digit *= 10;
                digit += input[i] - '0';
                i++;
            }

            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = digit;
            (*amount_tokens)++;
        } else if ((len - i >= 4) && strncmp(input + i, "sqrt", 4) == 0) { //сравниваем строки, если строка + н-ое количество элементов равны правильному значению, то приравниваем нужное число из дефайн аш
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = SQRT;
            (*amount_tokens)++;
            i += 4;
        } else if ((len - i >= 2) && (strncmp(input + i, "ln", 2) == 0)) {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = LN;
            (*amount_tokens)++;
            i += 2;
        } else if ((strncmp(input + i, "sin", 3) == 0) && (len - i >= 3)) {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = SIN;
            (*amount_tokens)++;
            i += 3;
        } else if ((strncmp(input + i, "cos", 3) == 0) && (len - i >= 3)) {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = COS;
            (*amount_tokens)++;
            i += 3;
        } else if ((strncmp(input + i, "tan", 3) == 0) && (len - i >= 3)) {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = TAN;
            (*amount_tokens)++;
            i += 3;
        } else if ((strncmp(input + i, "ctg", 3) == 0) && (len - i >= 3)) {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = CTG;
            (*amount_tokens)++;
            i += 3;
        } else if (input[i] == 'x') {
            tokens = realloc(tokens, (*amount_tokens + 1) * sizeof(int));
            tokens[*amount_tokens] = X;
            (*amount_tokens)++;
            i++;
        } else if (input[i] == ' ' || input[i] == '\t') {
            i++;
        } else {
            flag = 1;
            i++;
        }
    }

    if (flag) {
        *amount_tokens = 0;
        free(tokens);
        tokens = NULL;
    }
    return tokens;
}
