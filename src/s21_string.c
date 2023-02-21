#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *str) {
    char *buf = str;
    int length = 0;
    for (; *buf; ++buf) ++length;

    return length;
}

int s21_strcmp(char *str_cmp_first, char *str_cmp_second) {
    int strlen_first = s21_strlen(str_cmp_first);
    int strlen_second = s21_strlen(str_cmp_second);

    if (strlen_first == strlen_second) {
        for (int i = 0; i < strlen_first; i++) {
            if (str_cmp_first[i] != str_cmp_second[i]) {
                return 1;
            }
        }
    } else {
        return 1;
    }

    return 0;
}