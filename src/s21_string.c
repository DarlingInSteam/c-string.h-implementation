
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
    int result = 0;
    if (strlen_first > strlen_second)
        return 1;
    else if (strlen_first < strlen_second)
        return -1;
    if (strlen_first == strlen_second) {
        for (int i = 0; i < strlen_first; i++) {
            if (str_cmp_first[i] != str_cmp_second[i]) {
                if (str_cmp_first[i] > str_cmp_second[i]) {
                    result = 1;
                } else {
                    result = -1;
                }
            }
        }
    }

    return result;
}

char *s21_strcpy(char *str_cmp_first, char *str_cmp_second) {
    for (int i = 0; str_cmp_second[i] != '\0'; i++) str_cmp_first[i] = str_cmp_second[i];

    return str_cmp_first;
}

char *s21_strcat(char *str1, char *str2) {
    int size1 = s21_strlen(str1);
    int size2 = s21_strlen(str2);

    str1 = (char *)realloc(str1, size1 + size2);
    for (int i = size1, k = 0; i < size1 + size2; i++, k++) {
        str1[i] = str2[k];
    }
    return str1;
}

int s21_compare(char *str1, char *str2) {
    int res = 1;
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            res = 0;
        }
        str1++;
        str2++;
    }
    return res;
}

char *s21_strstr(char *str1, char *str2) {
    char *res = NULL;
    if (*str2 == '\0') {
        res = str1 + s21_strlen(str1);
        str1 += s21_strlen(str1);
    }
    while (*str1 != '\0') {
        if (*str1 == *str2) {
            if (s21_compare(str1, str2)) {
                res = str1;
                break;
            }
        }
        str1++;
    }
    return res;
}

char *s21_strchr(char *str1, int symbol) {
    char *p = NULL;
    for (int i = 0; i < s21_strlen(str1) + 1 || str1[i] != '\0'; i++) {
        if (str1[i] == symbol) {
            p = (str1 + i);
            break;
        }
    }
    return p;
}