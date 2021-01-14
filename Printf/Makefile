NAME	= libftprintf.a

SRCS	= ft_putunsigned_fd.c ft_putnbr_base.c ft_putadress_fd.c Libft/*.c ft_printf_get.c ft_printf_is_flag.c ft_printf_d_utils.c ft_printf_d.c ft_printf.c ft_printf_big_x.c ft_printf_c.c ft_printf_c_utils.c ft_printf_get.c ft_printf_d_utils_2.c ft_printf_is_flag.c ft_printf_s_utils.c ft_printf_p.c ft_printf_u_utils.c ft_printf_s.c ft_printf_x_utils.c ft_printf_x.c ft_printf_u.c ft_printf_utils.c ft_printf_get_2.c ft_printf_get_3.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

AR		= ar rc

RM		= rm -rf

INC		= -I includes/

CFLAGS	= -Wall -Werror -Wextra 

%.o: %.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $?

$(NAME):
			clang $(CFLAGS) -c $(SRCS)
			ar rc $(NAME) *.o

all:		$(NAME)

clean:
			$(RM) *.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
