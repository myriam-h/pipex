/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:36:53 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 23:26:09 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free0(t_s_pipe *p)
{
	ft_free(p->shell_commands);
	prog_exit("Memory allocation failure", false);
}

char	*duplicate_word(char *str)
{
	int		i;
	int		len;
	char	*word;

	len = ft_len(str);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	set_commands(t_s_pipe *p, char *argv[], int argc)
{
	int	j;
	int	k;
	int	len;

	j = 2;
	k = 0;
	if (p->delimiter != NULL)
	{
		len = argc - 4;
		j = 3;
	}
	else
		len = argc - 3;
	p->shell_commands = malloc(sizeof(char *) * (len + 1));
	if (!p->shell_commands)
		prog_exit("Memory allocation failure", false);
	while (j < argc - 1)
	{
		p->shell_commands[k] = duplicate_word(argv[j]);
		if (!p->shell_commands[k])
			ft_free0(p);
		k++;
		j++;
	}
	p->shell_commands[k] = NULL;
}
