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

int error_handle(DIR *dir)
{
    if (dir == NULL){
        perror("opendir");
        return (84);
    }
    return (0);
}

void arg_parse(int argc, char *argv[], flags_t *flag, paths_t *paths)
{
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-') {
            flag_parse(argv, i, flag);
        } else {
            paths->paths[paths->count] = argv[i];
            paths->count++;
        }
    }
    if (paths->count == 0){
        paths->paths[0] = ".";
        paths->count = 1;
    }
}

static long count_blocks(struct dirent *entry, char *path, flags_t *flag)
{
    struct stat st;
    char *full_path;
    long blocks = 0;

    if (flag->flag_a == false && entry->d_name[0] == '.')
        return 0;
    full_path = build_path(path, entry->d_name);
    if (stat(full_path, &st) == 0) {
        blocks = st.st_blocks;
    }
    free(full_path);
    return blocks;
}

static int get_block_size(char *path, flags_t *flag)
{
    long count = 0;
    struct dirent *entry;
    DIR *dir;

    dir = opendir(path);
    if (dir == NULL)
        return 0;
    entry = readdir(dir);
    while (entry != NULL){
        count += count_blocks(entry, path, flag);
        entry = readdir(dir);
    }
    closedir(dir);
    return count;
}

char *build_path(char *dir, char *file)
{
    int dir_len = my_strlen(dir);
    int file_len = my_strlen(file);
    char *path = malloc(dir_len + file_len + 2);

    if (path == NULL)
        return NULL;
    my_strcpy(path, dir);
    if (dir[dir_len - 1] != '/')
        my_strcat(path, "/");
    my_strcat(path, file);
    return path;
}

int process_path(char *path, flags_t *flag, int count_dir)
{
    DIR *dir;
    struct stat st;

    dir = opendir(path);
    if (error_handle(dir) == 0){
        stat(path, &st);
        if (count_dir > 1)
            my_printf("%s:\n", path);
        if (flag->flag_l == true){
            my_printf("total ");
            my_putnbr_long(get_block_size(path, flag) / 2);
            my_printf("\n");
        }
        detect_flag(path, dir, &st, flag);
        closedir(dir);
        return (0);
    } else
        return (84);
}

int main(int argc, char *argv[])
{
    flags_t flag;
    paths_t paths;
    int count_dir;
    int err;

    set_default(&flag, &paths);
    arg_parse(argc, argv, &flag, &paths);
    if (paths.count > 1){
        count_dir = paths.count;
    } else
        count_dir = 1;
    for (int i = 0; i < paths.count; i++){
        err = process_path(paths.paths[i], &flag, count_dir);
        if (count_dir && i < paths.count - 1 && err == 0)
            my_printf("\n");
        if (err == 84)
            exit(84);
    }
    free(paths.paths);
    return (0);
}
