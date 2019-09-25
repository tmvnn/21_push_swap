# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/09/25 17:27:57 by timuryakubo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_C = checker.c\
		operation.c\
		ps_atoi.c\
		stack_funcs.c\
		validation.c\
		opers1.c\
		opers2.c\
		fill_stack.c

SOURCES_PS = push_swap.c\
		fill_stack.c\
		stack_funcs.c\
		ps_atoi.c\
		validation.c\
		sort_2_3.c\
		sort_more.c\
		find_opt_ab_move.c\
		operation.c\
		opers1.c\
		opers2.c\
		ps_opers1.c\
		ps_opers2.c

SRCSDIR     = srcs
SRCS_C = $(addprefix $(SRCSDIR)/, $(SOURCES_C))
SRCS_PS = $(addprefix $(SRCSDIR)/, $(SOURCES_PS))

NAME_PS		= push_swap
NAME_C		= checker
WWW			= -Wall -Wextra -Werror
INCLUDES	= -I includes/

OBJDIR		= objs
OFILES 		= $(SOURCES:.c=.o)
OBJS 		= $(addprefix $(OBJDIR)/, $(OFILES))

all:
	make -C ./libft/
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_C) -o $(NAME_C)
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_PS) -o $(NAME_PS)

ch:
	/bin/rm -f $(NAME_C)
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_C) -o $(NAME_C)

ps:
	/bin/rm -f $(NAME_PS)
	cc -I ./libft/includes -L libft -lft $(INCLUDES) $(SRCS_PS) -o $(NAME_PS)

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_PS)

re: fclean all
