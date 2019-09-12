# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/09/12 17:56:41 by timuryakubo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_C = checker.c\
		operation.c\
		ps_atoi.c\
		stack_funcs.c\
		validation.c\
		opers1.c\
		opers2.c

SRCSDIR     = srcs
SRCS_C = $(addprefix $(SRCSDIR)/, $(SOURCES_C))

NAME_P		= push_swap
NAME_C		= checker
WWW			= -Wall -Wextra -Werror
INCLUDES	= -I includes/

OBJDIR		= objs
OFILES 		= $(SOURCES:.c=.o)
OBJS 		= $(addprefix $(OBJDIR)/, $(OFILES))

all:
	make -C ./libft/
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_C) -o $(NAME_C)

ch:
	/bin/rm -f $(NAME_C)
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_C) -o $(NAME_C)

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME_C)

re: fclean all
