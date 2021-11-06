# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Julian <Julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 14:05:04 by Julian            #+#    #+#              #
#    Updated: 2021/11/06 15:05:58 by Julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project

SRCS = srcs/get_nbrs.c srcs/swap.c srcs/pop.c


all: $(NAME)

push_swap:
	make -C libft
	gcc -Wall -Werror -Wextra srcs/push_swap.c srcs/sort_b.c srcs/get_groups.c srcs/has_members.c \
		srcs/sort_a.c $(SRCS) -L. libft/bin/libft.a -o push_swap

$(NAME): push_swap

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	/bin/rm -f push_swap
	make fclean -C libft

re: fclean all
