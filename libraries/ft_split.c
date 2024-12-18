#include "../pipex.h"

int ft_isspace(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

int count_words(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
            count++;
        while (*str && !ft_isspace(*str))
            str++;
    }
    return (count);
}

char *malloc_word(char *str)
{
    char *word;

    int i = 0;
    while (str[i] && !ft_isspace(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (str[i] && !ft_isspace(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str)
{
    char **arr;
    int i;

    i = 0;
    arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if (!arr || !str)
        return (NULL);
    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
        {
            arr[i] = malloc_word(str);
            i++;
        }
        while (*str && !ft_isspace(*str))
            str++;
    }
    arr[i] = NULL;
    return (arr);
}