NAME = libftprintf.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_point_hex.c ft_putchar_fd.c ft_putnbr_fd.c ft_putnbr_hex.c ft_putnbr_u_fd.c \
	ft_putstr_fd.c ft_printf.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

 %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
