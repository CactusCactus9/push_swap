# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 13:34:38 by abelkace          #+#    #+#              #
#    Updated: 2023/06/01 16:30:22 by abelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS =	./mandatory/utils.c \
		./mandatory/table.c \
		./mandatory/ft_join.c \
		./mandatory/ft_split.c \
		./mandatory/basic_utils.c \
		./mandatory/instructions.c \
		./mandatory/linked_lists.c \
		./mandatory/sort_three.c \
		./mandatory/sort_five.c \
		./mandatory/last_push.c \
		./mandatory/ft_double.c \
		./mandatory/push_swap.c

SRCS_BONUS = ./bonus/checker.c \
		./bonus/ft_split.c \
		./bonus/ft_join.c \
		./bonus/utils.c \
		./bonus/input.c \
		./bonus/ft_double.c \
		./bonus/basic_utils.c \
		./bonus/instructions.c \
		./bonus/linked_lists.c \
		./bonus/gnl/get_next_line.c \
		./bonus/gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) ./bonus/checker.h
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	
$(NAME) : $(OBJS) ./mandatory/push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c ./bonus/checker.h ./mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
