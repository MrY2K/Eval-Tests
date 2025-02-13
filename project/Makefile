CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I./include

NAME = push_swap

DEPS = ./include/push_swap.h

# Source files - Listed explicitly for clarity
SRC = src/main.c \
      src/libft/ft_list_manipulation.c \
      src/libft/ft_list_manipulation2.c \
      src/libft/ft_string_manipulation.c \
      src/libft/ft_string_manipulation_2.c \
      src/libft/ft_atoi.c \
      src/libft/ft_split.c \
      src/helpers/ft_validate_input.c \
      src/helpers/ft_free.c \
      src/helpers/ft_error.c \
      src/ops/ops1.c \
      src/ops/ops2.c \
      src/ops/ops3.c

OBJ = $(SRC:src/%.c=build/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

build/%.o: src/%.c $(DEPS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf build
      

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

#DONT FORGET TO ADD BONUS IF THERESE ANY