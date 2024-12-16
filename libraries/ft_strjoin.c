#include "../pipex.h"

int ft_len(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    int i;
    char *result;

    if (!s1 || !s2)
        return (NULL);
    result = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (*s1)
        result[i++] = *s1++;
    while (*s2)
        result[i++] = *s2++;
    result[i] = '\0';
    return (result);
}

void ft_strjoin_free(s_pipe *p, char *path)
{
    char *tempo;

    tempo = ft_strjoin(p->pathname, path);
    free(p->pathname);
    p->pathname = tempo;
    tempo = ft_strjoin(p->pathname, ":");
    free(p->pathname);
    p->pathname = tempo;
}