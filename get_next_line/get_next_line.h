/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:52:38 by mhabchi           #+#    #+#             */
/*   Updated: 2024/08/07 21:07:24 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list		*next;
	char				*s;
}	t_list;

char	*get_next_line(int fd);
t_list	*read_reserve(int fd, t_list **reserve);
void	add_to_reserve(t_list **reserve, char *buff, int read_char);
void	extract_line(t_list *reserve, char **line);
void	free_reserve(t_list **reserve);
void	create_line(t_list *reserve, char **line);
void	clean_reserve(t_list *reserve);
int		ft_strlen(const char *str);
int		newline_is_found(t_list *reserve);
t_list	*get_last_element(t_list *reserve);

#endif
