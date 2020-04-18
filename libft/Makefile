# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 01:12:41 by seunkim           #+#    #+#              #
#    Updated: 2020/03/28 16:57:53 by seunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_strlen.c \
		ft_strchr.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_strndup.c \
		gethexlen.c \
		ft_puthex.c

CC	=	gcc
FLAGS	=	-Wall -Werror -Wextra

OBJS	=	$(SRCS:%.c=%.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS)	:	$(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean	:	
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

