#include "shunting_yard.h"
#include "tokens.h"
#include "queue.h"

char *input_math_expression() {
    char *res = malloc(sizeof(char));
    int i = 0, break_flag = 1;

    while (break_flag == 1) {
        scanf("%c", &(res)[i]);
        char *temp = realloc(res, sizeof(char));

        if (temp != NULL) res = temp;
        if (res != NULL) {
            if (res[i] == '\n') { //ввод до нажатия ентера
                res[i] = '\0';
                break_flag = 0;
            }
        } else {
            free(res);
        }

        if (break_flag == 1) i++;
    }

    return res;
}

int priority_action(int token) {
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
    struct queue * result = NULL;
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
                result= push_queue(result, tokens[i]);
            } else if (is_function(tokens[i])) {
                temp_stack = push(temp_stack, tokens[i]);

            } else if (is_operator(tokens[i])) {
                while (temp_stack && is_operator(temp_stack->data) &&
                (priority(tokens[i]) < priority((int) temp_stack->data) ||
                (priority(tokens[i]) == priority((int) temp_stack->data) && associativity(tokens[i]) == 0))) {
                    result = push_queue(result, (int) temp_stack->data);
                    temp_stack = pop(temp_stack);
                }

                temp_stack = push(temp_stack, (double) tokens[i]);
            } else if (tokens[i] == -6) {
                temp_stack = push(temp_stack, tokens[i]);
            } else if (tokens[i] == -7) {
                int brace_flag = 1;

                while (temp_stack) {
                    if (temp_stack->data == -6) {
                        brace_flag = 0;
                        break;
                    } else {
                        result = push_queue(result, (int) temp_stack->data);
                        temp_stack = pop(temp_stack);
                    }
                }

                if (brace_flag) {
                    *flag = 1;
                    break;
                }

                temp_stack = pop(temp_stack);

                if (temp_stack && is_function(temp_stack->data)) {
                    result = push_queue(result, (int) temp_stack->data);
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
                result = push_queue(result, (int) temp_stack->data);
                temp_stack = pop(temp_stack);
            }
        }

        free(tokens);
    }

    free_stack(temp_stack);
    return result;
}