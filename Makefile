# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 15:33:53 by seunkim           #+#    #+#              #
#    Updated: 2020/03/24 19:20:46 by seunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC	=	gcc
FLAGS	=	-Wall -Werror -Wextra

SRCS	=	ft_printf.c checkformat.c displayflags.c displaypercent.c displaychar.c displaystring.c displayinteger.c
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME) :	$(OBJS)
	make -C ./libft/
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)

$(OBJS)	:	$(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean 	:
	rm -rf $(OBJS)
	make -C ./libft/ clean

fclean 	:	clean
	rm -rf $(NAME)
	make -C ./libft/ fclean

re	:	fclean all

.PHONY:	all fclean re
