#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();

int main() {
    s21_strlen_test();
    s21_strcmp_test();
}

void s21_strlen_test() {
    char *strlen_test_1 = "hello\0";
    char *strlen_test_2 = "\0";
    char *strlen_test_3 = "1\0";
    int str_size = 0;

    str_size = s21_strlen(strlen_test_1);

    if (str_size == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    str_size = s21_strlen(strlen_test_2);

    if (str_size == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    str_size = s21_strlen(strlen_test_3);

    if (str_size == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    char *strcmp_test_1_1 = "hello\0";
    char *strcmp_test_1_2 = "hello\0";
    char *strcmp_test_2_1 = "i'm artem\0";
    char *strcmp_test_2_2 = "are u danil?\0";
    char *strcmp_test_3_1 = "\0";
    char *strcmp_test_3_2 = "\0";

    int res_cmp = s21_strcmp(strcmp_test_1_1, strcmp_test_1_2);

    if (res_cmp == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    res_cmp = s21_strcmp(strcmp_test_2_1, strcmp_test_2_2);

    if (res_cmp == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    res_cmp = s21_strcmp(strcmp_test_3_1, strcmp_test_3_2);

    if (res_cmp == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}