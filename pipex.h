#ifndef PIPEX_H
#define PIPEX_H

#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h> // exit, malloc, ...
#include <fcntl.h> // O_CREAT
#include <unistd.h> 
#include <string.h> // strerror(errno)
#include <stdbool.h>
#include <sys/wait.h> // wait system call

typedef struct t_pipe
{
    char **shell_commands;
    char *pathname;
    char *delimiter;
    int  fd_infile;
    int  fd_outfile;
}   s_pipe;

// algorithm
//free_allocation.c
void check_if_NULL_p(s_pipe *p, char *pathname, char **command, char **directories);
void check_if_NULL_c(s_pipe *p, char **command, char **directories);
void check_if_NULL_d(s_pipe *p, char **directories);
void ft_free(char **var);
void free_exit_process(s_pipe *p, char **command, char **directories);
//initiate_commands.c
void pipe_ends_manage(int pipe_fd[2], int std, int fd, bool redirection);
void data_flow(s_pipe *p, int curr_pipe[2], int prev_pipe[2], int i);
void update_pipes(int curr_pipe_fd[2], int prev_pipe_fd[2], char **argv, int i);
void wait_process(int prev_pipe_fd[2], char **paths);
void initiate_commands(s_pipe *p, char *env[], char **paths);
//pipex.c
void input_user(s_pipe *p, int fd_stdin, int fd_temp, int saved_stdout);
void heredoc(s_pipe *p);
void handle_files(s_pipe *p, char *argv[], int argc);
void set_data(s_pipe *p);
void pipex(int argc, char *argv[], char *env[]);
//set_commands.c
void prog_exit(char *str, bool free_space);
char *duplicate_word(char *str);
void set_commands(s_pipe *p, char *argv[], int argc);
//set_pathname.c
char *is_available(s_pipe *p, char **command, char **directories);
void retrieve_commands_path(s_pipe *p, char **directories);
void set_pathname(s_pipe *p, char *env[]);
//startup.c
void prog_exit(char *str, bool free_space);
int is_empty(char *str);
void check_if_empty(char **argv);

// libraries
//ft_split_colon.c
char **ft_split_colon(char *str);
//ft_split.c
char **ft_split(char *str);
//ft_strjoin.c
int ft_len(const char *str);
char *ft_strjoin(const char *s1, const char *s2);
void ft_strjoin_free(s_pipe *p, char *path);
//ft_strncmp
int ft_strncmp(char *s1, char *s2, unsigned int n);

#endif