/*
** EPITECH PROJECT, 2025
** my
** File description:
** header include :/
*/


#ifndef MY_H_
    #define MY_H_
    #include <stdbool.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdarg.h>

typedef struct {
    bool flag_a;
    bool flag_l;
    bool flag_R;
    bool flag_d;
    bool flag_t;
} flags_t;

typedef struct {
    char **paths;
    int count;
    int capacity;
} paths_t;

void my_putchar(char c);
int my_putstr(const char *str);
int my_putnbr(int nb);
int my_strlen(char const *str);
int my_putnbr_long(long int nb);
int my_putnbr_unsigned(unsigned int nb);
int process_specifier_simple(char specifier, va_list ap, int count);
int process_specifier_complex(char specifier, va_list ap, int count);
int my_printf(const char *format, ...);
int loop_while_my_printf(const char *format, int *i, va_list ap);
int my_putnbr_octal(unsigned int nb);
int my_putnbr_hex_lower(unsigned long nb);
int my_putnbr_hex_upper(unsigned long nb);
int process_flag(char flag, va_list ap);
int my_put_pointer(char *ptr);
int process_length(char *flag, va_list ap);
int loopcheck(const char *flag, int *i, va_list ap, int count);
int my_check_is_digit(char c);
int my_put_float(double nb);
int my_compute_float(int part_int, int part_float, int count);
char my_strcpy(char *dest, char *src);
char my_strcat(char *dest, char *src);

void set_date(struct stat *st);
void detect_flag(char *path, DIR *dir, struct stat *st, flags_t *flag);
void print_permissions(mode_t mode, struct stat *st);
void set_default(flags_t *flag, paths_t *paths);
void flag_parse(char *argv[], int i, flags_t *flag);
void print_files(char *path, DIR *dir, flags_t *flag);
void print_files_a(char *path, DIR *dir, flags_t *flag);
void print_misc(struct stat *st);
int error_handle(DIR *dir);
void arg_parse(int argc, char *argv[], flags_t *flag, paths_t *paths);
int process_path(char *path, flags_t *flag, int count_dir);
void print_flag_d(char *dir, struct stat *st, flags_t *flag);
void print_flag_l(char *path, struct stat *st, flags_t *flag, DIR *dir);
char *build_path(char *dir, char *file);

#endif
