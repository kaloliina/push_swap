# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 17:03:26 by khiidenh          #+#    #+#              #
#    Updated: 2025/02/14 15:53:21 by khiidenh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT = libft/libft.a
SRC_DIR = src/
INC_DIR = -Iincludes -Ilibft/includes
SRCS =	$(SRC_DIR)error_handling.c\
		$(SRC_DIR)initialize_stack.c\
		$(SRC_DIR)push_swap.c\
		$(SRC_DIR)push.c\
		$(SRC_DIR)reverse_rotate.c\
		$(SRC_DIR)rotate.c\
		$(SRC_DIR)sort.c\
		$(SRC_DIR)stack_utils.c\
		$(SRC_DIR)swap.c\
		$(SRC_DIR)transition_to_a.c\
		$(SRC_DIR)transition_to_b.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC_DIR) $(OBJS) -L libft -lft -o $(NAME)

$(LIBFT):
	make -C libft

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
