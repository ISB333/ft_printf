######################## ARGUMENTS ########################

NAME = libftprintf.a
CFLAGS += -Wall -Wextra -Werror
CC = cc

######################## SOURCES ########################

SRCS = ft_printf.c ft_ptr.c \
	   ft_put_chars.c ft_put_hexa.c \
	   ft_itoa.c ft_itoa_unsigned.c main.c

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
	rm -f ${OBJS} ${NAME}

re: fclean all

test: ${NAME} main.o
		${CC} ${CFLAGS} main.o -o SuperTestGigaMegaPro3000 -L. -lftprintf

.PHONY: all clean fclean re test
