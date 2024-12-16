/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:52:07 by mhabchi           #+#    #+#             */
/*   Updated: 2024/06/26 04:52:07 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, size_t length)
{
	int		number;
	char	c;

	number = n;
	if (number == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (number < 0)
	{
		length++;
		ft_putchar_fd('-', fd);
		number = -number;
	}
	if (number >= 10)
		length = ft_putnbr_fd(number / 10, fd, length);
	c = number % 10 + '0';
	length++;
	ft_putchar_fd(c, fd);
	return (length);
}
