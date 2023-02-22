#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strstr_test();
void s21_strchr_test();

int main() {
#ifdef STRLEN
    s21_strlen_test();
#elif STRCMP
    s21_strcmp_test();
#elif STRCPY
    s21_strcpy_test();
#elif STRCAT
    s21_strcat_test();
#elif STRCHR
    s21_strchr_test();
#elif STRSTR
    s21_strstr_test();
#endif
}

void s21_strlen_test() {
    char *strlen_test_1 = "hello\0";
    char *strlen_test_2 = "\0";
    char *strlen_test_3 = "1\0";
    int str_size = 0;

    str_size = s21_strlen(strlen_test_1);
    printf("%s\n", strlen_test_1);
    printf("%d\n", str_size);
    if (str_size == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    str_size = s21_strlen(strlen_test_2);
    printf("%s\n", strlen_test_2);
    printf("%d\n", str_size);
    if (str_size == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    str_size = s21_strlen(strlen_test_3);
    printf("%s\n", strlen_test_3);
    printf("%d\n", str_size);
    if (str_size == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test() {
    char *strcmp_test_1_1 = "hello\0";
    char *strcmp_test_1_2 = "hello\0";
    char *strcmp_test_2_1 = "1\0";
    char *strcmp_test_2_2 = "123\0";
    char *strcmp_test_3_1 = "123\0";
    char *strcmp_test_3_2 = "1\0";

    int res_cmp = s21_strcmp(strcmp_test_1_1, strcmp_test_1_2);
    printf("%s\n", strcmp_test_1_1);
    printf("%s\n", strcmp_test_1_2);
    printf("%d\n", res_cmp);
    if (res_cmp == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    res_cmp = s21_strcmp(strcmp_test_2_1, strcmp_test_2_2);
    printf("%s\n", strcmp_test_2_1);
    printf("%s\n", strcmp_test_2_2);
    printf("%d\n", res_cmp);
    if (res_cmp == -1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    res_cmp = s21_strcmp(strcmp_test_3_1, strcmp_test_3_2);
    printf("%s\n", strcmp_test_3_1);
    printf("%s\n", strcmp_test_3_2);
    printf("%d\n", res_cmp);
    if (res_cmp == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test() {
    char *strcpy_test_1 = "hello\0";
    char *strcpy_test_2 = "1\0";
    char *strcpy_test_3 = "123\0";

    char *copy = malloc(s21_strlen(strcpy_test_1) * sizeof(char *));
    s21_strcpy(copy, strcpy_test_1);
    printf("%s\n", strcpy_test_1);
    printf("%s\n", copy);

    int result = s21_strcmp(copy, strcpy_test_1);

    if (result == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char *copy_2 = malloc(s21_strlen(strcpy_test_2) * sizeof(char *));
    s21_strcpy(copy_2, strcpy_test_2);
    printf("%s\n", strcpy_test_2);
    printf("%s\n", copy_2);

    result = s21_strcmp(copy_2, strcpy_test_2);

    if (result == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    char *copy_3 = malloc(s21_strlen(strcpy_test_3) * sizeof(char *));
    s21_strcpy(copy_3, strcpy_test_3);
    printf("%s\n", strcpy_test_3);
    printf("%s\n", copy_3);

    result = s21_strcmp(copy_3, strcpy_test_3);

    if (result == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    free(copy);
    free(copy_2);
    free(copy_3);
}

void s21_strcat_test() {
    char *test_1 = "Hello\0";
    char *test_2 = "Hi\0";
    char *test_3 = "I love banana\0";
    char *str = malloc(sizeof(char *));

    s21_strcat(str, test_1);
    printf("%s\n", test_1);
    printf("%s\n", "Hello\0");
    if (s21_strcmp(str, test_1)) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }

    s21_strcat(str, test_2);
    printf("%s\n", test_2);
    char *res2 = "Hi\0";
    printf("%s\n", "Hi\0");
    if (s21_strcmp(res2, str)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    s21_strcat(str, test_3);
    printf("%s\n", test_3);
    char *res3 = "I love banana\0";
    printf("%s\n", "I love banana\0");
    if (s21_strcmp(res3, str)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    free(str);
}

void s21_strchr_test() {
    char *test1 = "123\0";
    char *test2 = "\0";
    char *test3 = "Hello!\0";
    char *res;

    res = s21_strchr(test1, '3');
    printf("%s\n", test1);
    printf("%c\n", *res);
    if (*res == '3')
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strchr(test2, '\0');
    printf("%s\n", test2);
    printf("%s\n", res);
    if (res == test2)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strchr(test3, 'H');
    printf("%s\n", test3);
    printf("%c\n", 'H');
    if (test3[0] == 'H')
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strstr_test() {
    char *test1 = "Hello world, i love this world";
    char *test2 = "HElloo";
    char *test3 = "1\0";
    char *word1 = "world";
    char *word2 = "o";
    char *word3 = "\0";

    char *res;

    res = s21_strstr(test1, word1);
    printf("%s\n", test1);
    printf("%s\n", word1);
    printf("%s\n", res);
    if (s21_compare(res, word1))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strstr(test2, word2);
    printf("%s\n", test2);
    printf("%s\n", word2);
    printf("%s\n", res);
    if (s21_compare(res, word2))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strstr(test3, word3);
    printf("%s\n", test3);
    printf("%s\n", word3);
    printf("%s\n", res);
    if (s21_compare(res, word3))
        printf("SUCCESS");
    else
        printf("FAIL");
}