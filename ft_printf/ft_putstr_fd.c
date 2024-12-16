/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:52:02 by mhabchi           #+#    #+#             */
/*   Updated: 2024/06/26 04:52:02 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		length++;
		write(fd, s, 1);
		s++;
	}
	return (length);
}
