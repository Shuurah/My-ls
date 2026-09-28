/*
** EPITECH PROJECT, 2025
** process file
** File description:
** proceed
*/


#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int process_flag(char flag, va_list ap)
{
    int count = 0;

    switch (flag) {
        case '-':
            break;
        case '+':
            break;
        case ' ':
            break;
        case '0':
            break;
        case '#':
            break;
    }
    return count;
}

int process_length(char *flag, va_list ap)
{
    int count = 0;

    if (flag[0] == 'h' && flag[1] != 'h') {
    } else if (flag[0] == 'h' && flag[1] == 'h') {
    }
    if (flag[0] == 'l' && flag[1] != 'l') {
    } else if (flag[0] == 'l' && flag[1] == 'l') {
    }
    return count;
}

int check_char_flag(const char *flag, int *i, va_list ap, int count)
{
    char *base_flag = "-+ 0#";
    int len_flag = my_strlen(base_flag);

    for (int j = 0; j < len_flag; j++){
        if (flag[0] == base_flag[j]){
            count += process_flag(flag[0], ap);
            (*i)++;
        }
    }
    return (count);
}

int loopcheck(const char *flag, int *i, va_list ap, int count)
{
    char *base_specifier = "csdiuxXop%fFeg";
    int len_specifier = my_strlen(base_specifier);
    int stop = 0;

    if (flag[0] == 'h' || flag[0] == 'l'){
        (*i)++;
    }
    count += check_char_flag(flag, i, ap, count);
    for (int k = 0; k < len_specifier; k++){
        if (flag[0] == base_specifier[k]){
            count += process_specifier_simple(flag[0], ap, count);
            stop = 1;
            return (count);
        }
    }
    if (stop == 0)
        count += loopcheck(&flag[1], i, ap, count);
    return 0;
}
