/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** LS command
*/

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../../include/my.h"
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

void print_flag_d(char *dir, struct stat *st, flags_t *flag)
{
    if (flag->flag_l == true) {
        print_misc(st);
        my_printf("%s\n", dir);
    } else {
        my_printf("%s\n", dir);
    }
}

void print_flag_l(char *path, struct stat *st, flags_t *flag, DIR *dir)
{
    if (flag->flag_a == true) {
        print_files_a(path, dir, flag);
    } else {
        print_files(path, dir, flag);
    }
}

void flag_parse(char *argv[], int i, flags_t *flag)
{
    for (int j = 1; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'l')
            flag->flag_l = true;
        if (argv[i][j] == 'a')
            flag->flag_a = true;
        if (argv[i][j] == 'R')
            flag->flag_R = true;
        if (argv[i][j] == 'd')
            flag->flag_d = true;
        if (argv[i][j] == 't')
            flag->flag_t = true;
    }
}

void detect_flag(char *path, DIR *dir, struct stat *st, flags_t *flag)
{
    if (flag->flag_d == true){
        print_flag_d(path, st, flag);
        return;
    }
    if (flag->flag_l == true){
        print_flag_l(path, st, flag, dir);
        return;
    }
    if (flag->flag_a == true){
        print_files_a(path, dir, flag);
        return;
    }
    if (!flag->flag_a && !flag->flag_d && !flag->flag_R){
        if (!flag->flag_l && !flag->flag_t){
            print_files(path, dir, flag);
            return;
        }
    }
}

static void get_year(char *date_str, char *date_now)
{
    int current_year = 0;
    int file_year = 0;

    for (int i = 20; i < 24; i++) {
        file_year = file_year * 10 + (date_str[i] - '0');
        current_year = current_year * 10 + (date_now[i] - '0');
    }
    if (file_year - '0' == current_year - '0'){
        for (int i = 11; i < 16; i++) {
            my_printf("%c", date_str[i]);
        }
    } else {
        for (int i = 20; i < 24; i++){
            my_printf("%c", date_str[i]);
        }
    }
}

void set_date(struct stat *st)
{
    time_t current_date_t = time(NULL);
    char *date_str;
    char modified_date[4];
    char *current_date;

    current_date = ctime(&current_date_t);
    date_str = ctime(&st->st_mtime);
    date_str[my_strlen(date_str) - 1] = '\0';
    for (int i = 4; i < 7; i++)
        modified_date[i - 4] = date_str[i];
    modified_date[3] = '\0';
    my_printf("%s ", modified_date);
    for (int i = 8; i <= 9; i++) {
        if (my_check_is_digit(date_str[i]) == 1)
            my_printf("%c", date_str[i]);
    }
    my_printf(" ");
    get_year(date_str, current_date);
}
