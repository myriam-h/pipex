#include "../pipex.h"

void input_user(s_pipe *p, int fd_stdin, int fd_temp, int saved_stdout)
{
    char *line;
    
    ft_printf("Please input your data\n");
    dup2(fd_temp, STDOUT_FILENO);
    while (1)
    {
        line = get_next_line(fd_stdin); 
        if (line == NULL)
            break ;
        
        if (ft_strncmp(line, p->delimiter, ft_len(p->delimiter)) == 0)
            close(fd_stdin);
        else
            ft_printf("%s\n", line);
        free(line);
    }
    dup2(saved_stdout, STDOUT_FILENO);
}

void heredoc(s_pipe *p)
{
    int fd_temp;
    int fd_stdin;
    int saved_stdout;
    
    fd_temp = open(".heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0644 );
    if (fd_temp == -1)
        prog_exit(ft_strjoin("heredoc_infile : ", strerror(errno)), true);
    fd_stdin = dup(STDIN_FILENO);            
    saved_stdout = dup(STDOUT_FILENO);       
    input_user(p, fd_stdin, fd_temp, saved_stdout);
    close(fd_temp);
    close(saved_stdout);
}

void handle_files(s_pipe *p, char *argv[], int argc)
{
    if (strncmp("here_doc", argv[1], 8) == 0)
    {
        p->delimiter = argv[2];
        heredoc(p);
        p->fd_infile = open(".heredoc_file", O_RDONLY);
        if (p->fd_infile == -1)
            prog_exit(ft_strjoin("heredoc_infile : ", strerror(errno)), true);
        p->fd_outfile = open(argv[argc - 1], O_CREAT | O_WRONLY |O_TRUNC, 0644);
        if (p->fd_outfile == -1)
            prog_exit(ft_strjoin("heredoc_outfile : ", strerror(errno)), true);
    }
    else
    {
        p->fd_infile = open(argv[1], O_RDONLY);
        if (p->fd_infile == -1)
            prog_exit(ft_strjoin("infile : ", strerror(errno)), true);
        p->fd_outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (p->fd_outfile == -1)
            prog_exit(ft_strjoin("outfile : ", strerror(errno)), true);
    }
}

void set_data(s_pipe *p)
{
    p->shell_commands = NULL;
    p->pathname = NULL;
    p->delimiter = NULL;
    p->fd_infile = -1;
    p->fd_outfile = -1;
}

void pipex(int argc, char *argv[], char *env[])
{
    s_pipe p;
    
    set_data(&p);
    handle_files(&p, argv, argc);
    set_commands(&p, argv, argc);
    set_pathname(&p, env);
    initiate_commands(&p, env, ft_split_colon(p.pathname));
    free(p.pathname);
    ft_free(p.shell_commands);
}