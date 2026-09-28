##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## compile the lib and basic rules
##

CC	= epiclang

ARG = -o $(NAME)

SRC	= lib/my/my_printf/my_putchar.c \
	lib/my/my_printf/my_putnbr.c \
	lib/my/my_printf/my_putnbr_unsigned.c \
	lib/my/my_printf/my_putstr.c \
	lib/my/my_printf/my_strlen.c \
	lib/my/my_printf/my_printf.c \
	lib/my/my_printf/my_putnbr_octal.c \
	lib/my/my_printf/my_putnbr_hex.c \
	lib/my/my_printf/my_put_pointer.c \
	lib/my/my_printf/my_check_is_digit.c \
	lib/my/my_printf/my_put_float.c \
	lib/my/my_printf/process.c \
	lib/my/my_printf/process_specifier.c \
	lib/my/my_printf/libmini.c \
	lib/my/my_printf/my_strcpy.c \
	lib/my/my_printf/my_strcat.c \
	lib/my/my_ls.c \
	lib/my/print_ls.c \
	lib/my/main.c \

OBJ 	= $(SRC:.c=.o)

NAME	= my_ls

all:	libmy.a

libmy.a: $(OBJ)
	@$(CC) $(ARG) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: fclean all
re: fclean all
