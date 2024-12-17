/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:36:45 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 22:36:47 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	prog_exit(char *str, bool free_space)
{
	ft_printf("%s\n", str);
	if (free_space && str != NULL)
		free(str);
	exit(1);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	check_if_empty(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (is_empty(argv[i]) == 0)
			prog_exit("It must take 4 non-empty arguments", false);
		i++;
	}
}
