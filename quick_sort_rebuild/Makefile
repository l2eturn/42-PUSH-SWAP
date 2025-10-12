# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slimvutt <slimvut@fpgij;dgj;ds.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 05:21:09 by slimvutt          #+#    #+#              #
#    Updated: 2025/10/06 05:21:09 by slimvutt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -g3 -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS =	src/main.c\
		src/opt1.c\
		src/opt2.c\
		src/opt3.c\
		src/opt4.c\
		src/utils.c\
		src/free_utils.c\
		src/sort_utils.c\
		src/sort_algorithm.c\
		src/first_chunk.c\
		libft/libft.a\

SRCS_BONUS = 

$(NAME) : 
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) checker
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus :
	make bonus -C libft
	cc $(CFLAGS) $(SRCS_BONUS) -o checker
