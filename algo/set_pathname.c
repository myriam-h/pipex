#include "../pipex.h"

char *is_available(s_pipe *p, char **command, char **directories)
{
    char *pathname;
    char *tempo;
    int i;

    i = 0;
    while (directories[i])
    {
        tempo = ft_strjoin(directories[i], "/");
        if (!tempo)
            return (NULL);
        pathname  = ft_strjoin(tempo, command[0]);
        free(tempo);
        check_if_NULL_p(p, pathname, directories, command);
        if (access(pathname, X_OK) == 0)
            return (pathname);
        free(pathname);
        i++;
    }
    return (NULL);
}

void retrieve_commands_path(s_pipe *p, char **directories)
{
    char **command;
    char *path;
    int i;

    i = 0;
    while (p->shell_commands[i] != NULL)
    {
        command = ft_split(p->shell_commands[i++]);
        check_if_NULL_c(p, command, directories);
        path = is_available(p, command, directories);
        if (path != NULL)
        {
            if (p->pathname == NULL)
                p->pathname = ft_strjoin(path, ":");
            else
                ft_strjoin_free(p, path);
            free(path);
        }
        else
            free_exit_process(p, command, directories);
        ft_free(command);
    }
    if (p->pathname[ft_len(p->pathname) - 1] == ':')
        p->pathname[ft_len(p->pathname) - 1] = '\0';
}

void set_pathname(s_pipe *p, char *env[])
{
    char *path_value;
    char **directories;
    int i;

    path_value = NULL;
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path_value = env[i] + 5;
            break ;
        }
        i++;
    }
    if (!path_value)
    {
        ft_free(p->shell_commands);
        prog_exit("PATH not found", false);
    }
    directories = ft_split_colon(path_value);
    check_if_NULL_d(p, directories);
    retrieve_commands_path(p, directories);
    ft_free(directories);
}