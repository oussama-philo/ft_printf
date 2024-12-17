NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_addr.c ft_puthex.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned.c ft_strchr.c ft_node.c ft_handle_flags.c ft_pars_flag_type.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

bonus: all

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@ ar rcs ${NAME} ${OBJS}

clean:
	@ rm -f ${OBJS}

fclean: clean
	@ rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re, bonus
