/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:06:03 by mhabchi           #+#    #+#             */
/*   Updated: 2024/07/30 00:06:05 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned int n, int isupper)
{
	char	*hex_base;
	char	hex[9];
	int		length;
	int		i;

	hex_base = "0123456789abcdef";
	if (isupper)
		hex_base = "0123456789ABCDEF";
	i = 8;
	length = 0;
	hex[i] = '\0';
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (n > 0)
	{
		length++;
		hex[--i] = hex_base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(&hex[i], 1);
	return (length);
}
