#include "shunting_yard.h"

#include <string.h>

#include "matrix.h"
#include "queue.h"
#include "stack.h"
#include "tokens.h"

char *readline_() {
    char buf[81] = {0};
    char *res = NULL, *tmp;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = (int)strlen(buf);
            int str_len = len + chunk_len;
            tmp = realloc(res, str_len + 1);
            if (tmp == NULL) {
            } else {
                res = tmp;
            }
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

int priority(int token) {
    int ans;

    switch (token) {
        case -2:
            ans = 3;
            break;
        case -4:
        case -5:
            ans = 2;
            break;
        case -1:
        case -3:
            ans = 1;
            break;
    }

    return ans;
}

int associativity(int token) {
    int ans;

    switch (token) {
        case -1:
        case -3:
        case -4:
        case -5:
            ans = 0;
            break;
        case -2:
            ans = 1;
            break;
    }

    return ans;
}

struct queue *shunting_yard(char *input, int *flag) {
    struct queue *result = NULL;
    int amount_tokens = 0;
    int *tokens = read_tokens(input, &amount_tokens);
    struct stack *temp_stack = NULL;

    *flag = 0;
    if (!tokens) {
        *flag = 1;
    } else {
        int i = 0;
        while (i < amount_tokens) {
            if (tokens[i] > -1 || tokens[i] == -14) {
                result = push_queue(result, tokens[i]);
            } else if (is_function(tokens[i])) {
                temp_stack = push(temp_stack, tokens[i]);

            } else if (is_operator(tokens[i])) {
                while (temp_stack && is_operator(temp_stack->data) &&
                       (priority(tokens[i]) < priority((int)temp_stack->data) ||
                        (priority(tokens[i]) == priority((int)temp_stack->data) &&
                         associativity(tokens[i]) == 0))) {
                    result = push_queue(result, (int)temp_stack->data);
                    temp_stack = pop(temp_stack);
                }

                temp_stack = push(temp_stack, (double)tokens[i]);
            } else if (tokens[i] == -6) {
                temp_stack = push(temp_stack, tokens[i]);
            } else if (tokens[i] == -7) {
                int brace_flag = 1;

                while (temp_stack) {
                    if (temp_stack->data == -6) {
                        brace_flag = 0;
                        break;
                    } else {
                        result = push_queue(result, (int)temp_stack->data);
                        temp_stack = pop(temp_stack);
                    }
                }

                if (brace_flag) {
                    *flag = 1;
                    break;
                }

                temp_stack = pop(temp_stack);

                if (temp_stack && is_function(temp_stack->data)) {
                    result = push_queue(result, (int)temp_stack->data);
                    temp_stack = pop(temp_stack);
                }
            }

            i++;
        }

        if (!*flag) {
            while (temp_stack) {
                if (temp_stack->data == -6 || temp_stack->data == -7) {
                    *flag = 1;
                    break;
                }
                result = push_queue(result, (int)temp_stack->data);
                temp_stack = pop(temp_stack);
            }
        }

        free(tokens);
    }

    free_stack(temp_stack);
    return result;
}