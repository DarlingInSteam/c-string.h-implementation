#include "shunting_yard.h"

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