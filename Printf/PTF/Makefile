NAME	= libftprintf.a

SRCS	= ft_putunsigned_fd.c ft_putnbr_base.c ft_putadress_fd.c Libft/*.c ft_printf_get.c ft_printf_is_flag.c ft_printf_d_utils.c ft_printf_d.c ft_printf.c

OBJS	= $(SRCS:.c=.o)

LIB		= prinft.h Libft/libft.h

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
