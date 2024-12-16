/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:09:31 by mhabchi           #+#    #+#             */
/*   Updated: 2024/07/30 00:09:33 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u_fd(unsigned int n, int fd, size_t length)
{
	unsigned int	number;
	char			c;

	number = n;
	if (number >= 10)
		length = ft_putnbr_u_fd(number / 10, fd, length);
	c = number % 10 + '0';
	length++;
	ft_putchar_fd(c, fd);
	return (length);
}
