# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 13:33:45 by pyathams          #+#    #+#              #
#    Updated: 2024/05/25 14:03:49 by pyathams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Include directories
INC = -Iinc
INCLUDELIBFT = -Ilibft

# Source files
SRCS = src/errors_handle.c \
       src/inti_nodes_a.c \
       src/inti_nodes_b.c \
       src/intial_condition_utils.c \
       src/main.c \
       src/push_swap.c \
       src/push.c \
       src/reverse_rotate.c \
       src/rotate.c \
       src/sort_stacks.c \
       src/stack_init_utilis.c \
       src/stack_init.c \
       src/swap.c \
       src/three_list_sort.c

# Object files
OBJ = $(SRCS:%.c=%.o)

# Executable name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Default target
all: $(NAME)

# Rule for building object files
%.o: %.c
	@echo "Compiling $< with includes: $(INC) $(INCLUDELIBFT)"
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) -c $< -o $@

# Rule for building the executable
$(NAME): $(OBJ) libft
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) -o $(NAME) $(OBJ) -Llibft -lft

# Rule for building the libft library
libft:
	make -C libft

# Clean object files
clean:
	make clean -C libft
	$(RM) $(OBJ)

# Clean object files and executable
fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re libft


