NAME =      pipex
INCLUDES =  ./
PRINTF =    ft_printf/libftprintf.a

CC =        gcc
CFLAGS =    -Wall -Wextra -Werror

SRCS =      main.c libraries/ft_split_colon.c libraries/ft_split.c libraries/ft_strjoin.c libraries/ft_strncmp.c \
            algo/free_allocation.c algo/initiate_commands.c algo/pipex.c algo/set_commands.c \
            algo/set_pathname.c algo/startup.c

BSRCS =     bonus/bonus_part.c libraries/ft_split_colon.c libraries/ft_split.c libraries/ft_strjoin.c libraries/ft_strncmp.c \
            algo/free_allocation.c algo/initiate_commands.c algo/pipex.c algo/set_commands.c \
			algo/set_pathname.c algo/startup.c

GNL =       get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

OBJS =      $(SRCS:.c=.o)
BOBJS =     $(BSRCS:.c=.o)

all:        $(NAME)

%.o:        %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):    $(OBJS) $(PRINTF)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(GNL)

$(PRINTF):  
			@make -C ./ft_printf

bonus:      $(BOBJS) $(PRINTF)
			@$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(PRINTF) $(GNL)

clean:      
			@make clean -C ./ft_printf
			@rm -f $(OBJS)
			@rm -f $(BOBJS)

fclean:     clean
			@make fclean -C ./ft_printf
			rm -f $(NAME)

re:         fclean all

.PHONY:     all bonus clean fclean re