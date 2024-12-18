#include "../pipex.h"

int main(int argc, char *argv[], char *env[])
{
    if (argc < 5)
    {
        ft_printf("The arguments shall be represented in the following form :");
        prog_exit("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", false);
    }
    else if (argc < 6 && argv[1] && ft_strncmp("here_doc", argv[1], 8) == 0)
    {
        ft_printf("The arguments shall be represented in the following form :");
        prog_exit("./pipex here_doc LIMITER cmd cmd1 file\n", false);
    }
    else
    {
        check_if_empty(argv);
        pipex(argc, argv, env);
    }
}