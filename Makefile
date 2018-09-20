# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtshukud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 15:24:19 by mtshukud          #+#    #+#              #
#    Updated: 2018/09/08 15:07:47 by mtshukud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG  = -Wall -Wextra -Werror

NAME = ft_ls

SRC = ft_ls.c\
	  ft_strdup.c\
	  ft_strcmp.c\
	  ft_get_opt.c\
	  ft_options.c\
	  ft_initializer.c\
	  ft_trim.c\
	  ft_xit.c\
	  ft_putchar.c\
	  ft_putnbr.c\
	  ft_putstr.c\
	  ft_strcpy.c\
	  ft_strcat.c\
	  ft_bzero.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@gcc -o $(NAME) $(FLAG) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean , flcean, re
