#include "../pipex.h"

void check_if_NULL_p(s_pipe *p, char *pathname, char **command, char **directories)
{
    if (!pathname)
    {
        ft_free(directories);
        ft_free(p->shell_commands);
        ft_free(command);
        prog_exit("Memory Allocation Failure", false);
    }
}

void check_if_NULL_c(s_pipe *p, char **command, char **directories)
{
    if (!command)
    {
        ft_free(directories);
        ft_free(p->shell_commands);
        prog_exit("Memory Allocation Failure", false);
    }
}

void check_if_NULL_d(s_pipe *p, char **directories)
{
    if (!directories)
    {
        ft_free(p->shell_commands);
        prog_exit("Memory Allocation Failure", false);
    }
}

void ft_free(char **var)
{
    int i;

    i = 0;
    if (!var)
        return ;
    while (var[i] != NULL)
    {
        free(var[i]);
        i++;
    }
    free(var);
}

void free_exit_process(s_pipe *p, char **command, char **directories)
{
    ft_free(p->shell_commands);
    free(p->pathname);
    ft_free(command);
    ft_free(directories);
    prog_exit("command not found", false);
}