#include "pipex.h"

int main(int argc, char *argv[], char *env[])
{
    
    if (argc == 5)
    {
        check_if_empty(argv);
        pipex(argc, argv, env);
    }
    else
        prog_exit("It must take 4 arguments", false);
}