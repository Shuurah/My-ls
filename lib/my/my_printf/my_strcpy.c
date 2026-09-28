/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** strcpy command
*/

char my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return *dest;
}
