/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:01:08 by mhabchi           #+#    #+#             */
/*   Updated: 2024/07/30 00:01:09 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_point_hex(va_list args)
{
	uintptr_t	address;
	void		*ptr;
	char		hex[17];
	int			length;
	int			i;

	ptr = va_arg(args, void *);
	address = (uintptr_t) ptr;
	length = 0;
	i = 16;
	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	hex[i--] = '\0';
	if (address == 0)
		hex[i--] = '0';
	while (address != 0)
	{
		hex[i--] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	length += ft_putstr_fd("0x", 1);
	length += ft_putstr_fd(hex + i + 1, 1);
	return (length);
}
