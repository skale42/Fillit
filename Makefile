# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:09:34 by mstefani          #+#    #+#              #
#    Updated: 2019/12/10 17:16:30 by mstefani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS	=-I fillit.h

SRC = fillit.c \
		ft_makeup.c \
		ft_calc.c \
		ft_calc_field.c \
		ft_greate_first_list.c \
		ft_add_list.c \
		ft_l.c \
		ft_find_x.c \
		ft_mleft.c \
		ft_mright.c \
		ft_mup.c \
		ft_puzzle.c \
		print_res.c \
		ft_can_we_movex.c \
		ft_can_we_movey.c \
		ft_free_list.c \
		schet1.c

LIBOBJ=$(SRC:.c=.o)

LIBNAME = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) $(LIBNAME) -o $(NAME) $(HEADERS)

%.o:%.c
	gcc $(CFLAGS) $< -c -o $@

all: $(NAME)
   
clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)

re: fclean all
