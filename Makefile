# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 19:19:26 by wmozella          #+#    #+#              #
#    Updated: 2022/03/11 20:12:44 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_atoi.c\
	ft_check.c\
	ft_swap.c\
	ft_reverse.c\
	ft_sorting.c\
	push_swap.c\
	ft_sorting_utils.c\

HDRS = push_swap.h

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		$(CC) $(FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean