/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:37:31 by mhabchi           #+#    #+#             */
/*   Updated: 2024/07/29 22:37:35 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	form_hexa(va_list args, const char form_spec)
{
	int				length;
	unsigned int	n;

	length = 0;
	if (form_spec == 'x')
	{
		n = va_arg(args, unsigned int);
		return (ft_putnbr_hex(n, 0));
	}
	if (form_spec == 'X')
	{
		n = va_arg(args, unsigned int);
		return (ft_putnbr_hex(n, 1));
	}
	if (form_spec == 'p')
		return (ft_point_hex(args));
	return (length);
}

int	form_char(va_list args, const char form_spec)
{
	int		length;
	char	*str;

	length = 0;
	if (form_spec == 'c')
		length = ft_putchar_fd(va_arg(args, int), 1);
	if (form_spec == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			length = ft_putstr_fd("(null)", 1);
		else
			length = ft_putstr_fd(str, 1);
	}
	return (length);
}

int	form_nbr(va_list args, const char form_spec )
{
	int	length;

	length = 0;
	if (form_spec == 'd' || form_spec == 'i')
		length = ft_putnbr_fd(va_arg(args, int), 1, 0);
	if (form_spec == 'u')
		length = ft_putnbr_u_fd(va_arg(args, int), 1, 0);
	return (length);
}

int	check_form(va_list args, const char form_spec)
{
	if (form_spec == 'd' || form_spec == 'i' || form_spec == 'u' )
		return (form_nbr(args, form_spec));
	if (form_spec == 'c' || form_spec == 's')
		return (form_char(args, form_spec));
	if (form_spec == 'p' || form_spec == 'x' || form_spec == 'X')
		return (form_hexa(args, form_spec));
	if (form_spec == '%')
	{
		ft_putchar_fd(form_spec, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *form_str, ...)
{
	size_t	length;
	size_t	i;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, form_str);
	while (form_str[i])
	{
		if (form_str[i] == '%')
		{
			i++;
			length += check_form(args, form_str[i]);
		}
		else
		{
			ft_putchar_fd(form_str[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}