# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Julian <Julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 11:32:02 by Julian            #+#    #+#              #
#    Updated: 2021/10/16 11:32:03 by Julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = $(filter-out $(BSOURCES), $(wildcard *.c))
BSOURCES = $(wildcard *lst*.c)
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	ar rc $(NAME) $?

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
