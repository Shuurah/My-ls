/*
** EPITECH PROJECT, 2025
** str len
** File description:
** str len
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (*str != '\0'){
        str++;
        count++;
    }
    return (count);
}
