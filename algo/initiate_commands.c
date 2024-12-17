/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:37:07 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 22:37:08 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_ends_manage(int pipe_fd[2], int std, int fd, bool redirection)
{
	if (!redirection)
		dup2(fd, std);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	data_flow(t_s_pipe *p, int curr_pipe[2], int prev_pipe[2], int i)
{
	if (i == 0)
		dup2(p->fd_infile, STDIN_FILENO);
	else
		pipe_ends_manage(prev_pipe, STDIN_FILENO, prev_pipe[0], false);
	if (p->shell_commands[i + 1] != NULL)
		pipe_ends_manage(curr_pipe, STDOUT_FILENO, curr_pipe[1], false);
	else
		dup2(p->fd_outfile, STDOUT_FILENO);
}

void	update_pipes(int curr_pipe_fd[2], int prev_pipe_fd[2],
			char **argv, int i)
{
	if (i != 0)
	{
		pipe_ends_manage(prev_pipe_fd, -1, 0, true);
	}
	prev_pipe_fd[0] = curr_pipe_fd[0];
	prev_pipe_fd[1] = curr_pipe_fd[1];
	ft_free(argv);
}

void	wait_process(int prev_pipe_fd[2], char **paths)
{
	ft_free(paths);
	pipe_ends_manage(prev_pipe_fd, -1, 0, true);
	while (wait(NULL) > 0)
		;
}

void	initiate_commands(t_s_pipe *p, char *env[], char **paths)
{
	int		i;
	pid_t	pid;
	int		curr_pipe_fd[2];
	int		prev_pipe_fd[2];
	char	**argv;

	i = 0;
	while (p->shell_commands[i])
	{
		if (p->shell_commands[i + 1] != NULL)
			if (pipe(curr_pipe_fd) == -1)
				prog_exit(ft_strjoin("pipe failed :", strerror(errno)), true);
		pid = fork();
		argv = ft_split(p->shell_commands[i]);
		if (pid == -1)
			prog_exit(ft_strjoin("fork failed :", strerror(errno)), true);
		if (pid == 0)
		{
			data_flow(p, curr_pipe_fd, prev_pipe_fd, i);
			execve(paths[i], argv, env);
			prog_exit(ft_strjoin("execution failed :", strerror(errno)), true);
		}
		update_pipes(curr_pipe_fd, prev_pipe_fd, argv, i++);
	}
	wait_process(prev_pipe_fd, paths);
}
