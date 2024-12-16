#include "../pipex.h"

char *duplicate_word(char *str)
{
    int i;
    int len;
    char *word;

    len = ft_len(str);
    word = (char *)malloc(sizeof(char) * (len + 1));
    i = 0;
    while (str[i])
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

void set_commands(s_pipe *p, char *argv[], int argc)
{
    int j;
    int k;
    int len;

    j = 2;
    k = 0;
    if (p->delimiter != NULL)
    {
        len = argc - 4;
        j = 3;
    }
    else
        len = argc - 3;
    p->shell_commands = (char **)malloc(sizeof(char *) * (len + 1)); // it needs to be freed later on
    if (!p->shell_commands)
        prog_exit("Memory allocation failure", false);
    while (j < argc - 1)
        p->shell_commands[k++] = duplicate_word(argv[j++]);
    p->shell_commands[k] = NULL;
}