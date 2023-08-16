/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare two string and tells which one is the biggest
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    i++;
    return 0;
}
