/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:19:06 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 23:27:01 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_pipe
{
	char	**shell_commands;
	char	*pathname;
	char	*delimiter;
	int		fd_infile;
	int		fd_outfile;
}			t_s_pipe;

void	check_if_n_p(t_s_pipe *p, char *pathname, char **command,
			char **directories);
void	check_if_n_c(t_s_pipe *p, char **command, char **directories);
void	check_if_n_d(t_s_pipe *p, char **directories);
void	ft_free(char **var);
void	free_exit_process(t_s_pipe *p, char **command, char **directories);
void	pipe_ends_manage(int pipe_fd[2], int std, int fd, bool redirection);
void	data_flow(t_s_pipe *p, int curr_pipe[2], int prev_pipe[2], int i);
void	update_pipes(int curr_pipe_fd[2], int prev_pipe_fd[2], char **argv,
			int i);
void	wait_process(int prev_pipe_fd[2], char **paths);
void	initiate_commands(t_s_pipe *p, char *env[], char **paths);
void	input_user(t_s_pipe *p, int fd_stdin, int fd_temp, int saved_stdout);
void	heredoc(t_s_pipe *p);
void	handle_files(t_s_pipe *p, char *argv[], int argc);
void	set_data(t_s_pipe *p);
void	pipex(int argc, char *argv[], char *env[]);
void	prog_exit(char *str, bool free_space);
void	ft_free0(t_s_pipe *p);
char	*duplicate_word(char *str);
void	set_commands(t_s_pipe *p, char *argv[], int argc);
char	*is_available(t_s_pipe *p, char **command, char **directories);
void	retrieve_commands_path(t_s_pipe *p, char **directories);
void	set_pathname(t_s_pipe *p, char *env[]);
int		is_empty(char *str);
void	check_if_empty(char **argv);
char	**ft_split_colon(char *str);
char	**ft_split(char *str);
int		ft_len(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_strjoin_free(t_s_pipe *p, char *path);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
