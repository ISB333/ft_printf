######################## ARGUMENTS ########################

NAME = libftprintf.a
CFLAGS += -Wall -Wextra -Werror
CC = cc

######################## SOURCES ########################

SRCS = ft_printf.c ft_ptr.c \
	   ft_put_chars.c ft_put_hexa.c \
	   ft_itoa.c ft_itoa_unsigned.c

OBJS = ${SRCS:.c=.o}

######################## RULES ########################

all: ${NAME}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
