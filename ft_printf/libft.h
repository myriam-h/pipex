/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:50:04 by mhabchi           #+#    #+#             */
/*   Updated: 2024/06/26 04:50:06 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include  <stdint.h>
# include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, int isupper);
int	ft_putnbr_fd(int n, int fd, size_t length);
int	ft_putnbr_u_fd(unsigned int n, int fd, size_t length);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_point_hex(va_list args);
int	ft_strlen(const char *str);

#endif
