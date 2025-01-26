CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

SRCS = ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putnbr_unsigned.c ft_putstr.c
OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
