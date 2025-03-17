CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar -rcs

PRINTF_DIR  = src/ft_printf
DPRINTF_DIR = src/ft_dprintf
OBJ_DIR     = obj

# Combined header file (in the root)
COMBINED_HDR = inc/ft_printf.h

# Source files with their paths
SRCS_PRINTF  = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar.c $(PRINTF_DIR)/ft_puthexa.c $(PRINTF_DIR)/ft_putnbr.c $(PRINTF_DIR)/ft_putnbr_unsigned.c $(PRINTF_DIR)/ft_putstr.c
SRCS_DPRINTF = $(DPRINTF_DIR)/ft_dprintf.c $(DPRINTF_DIR)/ft_dputchar.c $(DPRINTF_DIR)/ft_dputhexa.c $(DPRINTF_DIR)/ft_dputnbr.c $(DPRINTF_DIR)/ft_dputnbr_unsigned.c $(DPRINTF_DIR)/ft_dputptr.c $(DPRINTF_DIR)/ft_dputstr.c

SRCS = $(SRCS_PRINTF) $(SRCS_DPRINTF)

# Convert sources to object filenames.
# We use only the filename (assuming they are unique) and prefix with OBJ_DIR.
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Tell make to look for .c files in both source directories.
vpath %.c $(PRINTF_DIR) $(DPRINTF_DIR)

NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Create the obj directory if it doesn't exist.
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pattern rule to compile any .c file into an object in the obj directory.
$(OBJ_DIR)/%.o: %.c $(COMBINED_HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Optional test target: compiles a main.c (in the root) linking with the static library.
test: $(NAME)
	$(CC) main.c $(NAME) -o test
	./test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test
