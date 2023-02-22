#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(char *str);
int s21_strcmp(char *str_cmp_first, char *str_cmp_second);
char *s21_strcpy(char *str_cmp_first, char *str_cmp_second);
char *s21_strcat(char *str1, char *str2);
int s21_compare(char *str1, char *str2);
char *s21_strstr(char *str1, char *str2);
char *s21_strchr(char *str1, int symbol);

#endif
