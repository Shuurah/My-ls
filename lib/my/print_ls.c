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



static char get_file_type(mode_t mode)
{
    if (S_ISDIR(mode))
        return 'd';
    if (S_ISLNK(mode))
        return 'l';
    if (S_ISBLK(mode))
        return 'b';
    if (S_ISCHR(mode))
        return 'c';
    if (S_ISFIFO(mode))
        return 'p';
    if (S_ISSOCK(mode))
        return 's';
    return '-';
}

void print_permissions(mode_t mode, struct stat *st)
{
    my_printf("%c", get_file_type(mode));
    my_printf("%c", (mode & S_IRUSR) ? 'r' : '-');
    my_printf("%c", (mode & S_IWUSR) ? 'w' : '-');
    my_printf("%c", (mode & S_IXUSR) ? 'x' : '-');
    my_printf("%c", (mode & S_IRGRP) ? 'r' : '-');
    my_printf("%c", (mode & S_IWGRP) ? 'w' : '-');
    my_printf("%c", (mode & S_IXGRP) ? 'x' : '-');
    my_printf("%c", (mode & S_IROTH) ? 'r' : '-');
    my_printf("%c", (mode & S_IWOTH) ? 'w' : '-');
    my_printf("%c ", (mode & S_IXOTH) ? 'x' : '-');
}

void print_misc(struct stat *st)
{
    print_permissions(st->st_mode, st);
    my_putnbr_long(st->st_nlink);
    my_printf(" %s ", getpwuid(st->st_uid)->pw_name);
    my_printf("%s ", getgrgid(st->st_gid)->gr_name);
    my_putnbr_long(st->st_size);
    my_printf(" ");
    set_date(st);
    my_printf(" ");
}

void set_default(flags_t *flag, paths_t *paths)
{
    flag->flag_l = false;
    flag->flag_a = false;
    flag->flag_R = false;
    flag->flag_d = false;
    flag->flag_t = false;
    paths->count = 0;
    paths->paths = malloc(paths->capacity * sizeof(char *));
    if (paths->paths == NULL) {
        perror("malloc");
        exit(84);
    }
}

void print_files(char *path, DIR *dir, flags_t *flag)
{
    struct dirent *entry;
    struct stat st;
    char *full_path;

    entry = readdir(dir);
    while (entry != NULL){
        full_path = build_path(path, entry->d_name);
        stat(entry->d_name, &st);
        if (entry->d_name[0] != '.' && flag->flag_l == true) {
            print_misc(&st);
            my_printf("%s\n", entry->d_name);
        }
        if (entry->d_name[0] != '.' && flag->flag_l == false) {
            my_printf("%s\n", entry->d_name);
        }
        entry = readdir(dir);
    }
}

void print_files_a(char *path, DIR *dir, flags_t *flag)
{
    struct dirent *entry;
    struct stat st;

    entry = readdir(dir);
    while (entry != NULL){
        stat(entry->d_name, &st);
        if (flag->flag_l == true) {
            print_misc(&st);
            my_printf("%s\n", entry->d_name);
        } else
            my_printf("%s\n", entry->d_name);
        entry = readdir(dir);
    }
}
