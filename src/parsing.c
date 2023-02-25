#include "parsing.h"
//ввод мат выражения
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
//проверка правильности ввода
int validation_input(char *input) {

}
//проверка является ли числом
int is_num(char ch) {
    if ((ch <= '9' && ch >= '0') || ch == '.' || ch == ',' || ch == 'x') {
        return 1;
    } 

    return 0;
}
//проверка является ли функцией
int is_func(char ch) {
    //        sin          cos          tg           ctg          sqrt          ln
    if (ch == 's' || ch == 'c' || ch == 't' || ch == 'g' || ch == 'q' || ch == 'l') {
        return 1;
    }

    return 0;
}
//является ли математическим символом
int is_math_symbol(char ch) {
    if (ch == '*' || ch == '-' || ch == '+' || ch == '/' || ch == '^' || ch == '(' ||
      ch == '~') {
        return 1;
      }

      return 0;
}