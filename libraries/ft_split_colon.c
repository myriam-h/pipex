#include "../pipex.h"

int ft_iscolon(char c)
{
    return (c == ':');
}
    
int count_words_colon(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        if (!ft_iscolon(*str))
            count++;
        while (*str && !ft_iscolon(*str))
            str++;
        if (*str && ft_iscolon(*str))
            str++;
    }
    return (count);
}

char *malloc_word_colon(char *str)
{
    char *word;
    int i;

    i = 0;
    while (str[i] && !ft_iscolon(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (str[i] && !ft_iscolon(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split_colon(char *str)
{
    int i;
    char **arr;

    arr = (char **)malloc(sizeof(char *) * (count_words_colon(str) + 1));
    if (!arr)
        return (NULL);
    i = 0;
    while (*str)
    {
        if (!ft_iscolon(*str))
        {
            arr[i] = malloc_word_colon(str);
            i++;
        }
        while (*str && !ft_iscolon(*str))
            str++;
        if (*str && ft_iscolon(*str))
            str++;
    }
    arr[i] = NULL;
    return (arr);
}