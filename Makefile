# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/10/06 19:10:13 by lbellona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES_C = checker.c\
		operation.c\
		ps_atoi.c\
		stack_funcs.c\
		validation.c\
		opers1.c\
		opers2.c\
		fill_stack.c\
		print_funcs.c

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
		ps_opers2.c\
		print_funcs.c

WWW = -Wall -Wextra -Werror

CH 			= checker
PS 			= push_swap

SRCSDIR     = srcs
SRCS_C 		= $(addprefix $(SRCSDIR)/, $(SOURCES_C))
SRCS_PS 	= $(addprefix $(SRCSDIR)/, $(SOURCES_PS))

OBJS_CH 	= $(SOURCES_C:.c=.o)
OBJS_CH_DIR = $(addprefix $(SRCSDIR)/, $(OBJS_CH))
OBJS_PS 	= $(SOURCES_PS:.c=.o)
OBJS_PS_DIR = $(addprefix $(SRCSDIR)/, $(OBJS_PS))

NAME_PS		= push_swap
NAME_C		= checker
INCLUDES	= -I includes/ -I libft/includes -I ft_printf/includes

all: liba printf $(CH) $(PS)

liba:
	make -C ./libft/

printf:
	make -C ./ft_printf/

$(CH): $(OBJS_CH_DIR)
	cc $(WWW) $(OBJS_CH_DIR) -o $@  -L libft -lft -L ft_printf -lftprintf

$(PS): $(OBJS_PS_DIR)
	cc $(WWW) $(OBJS_PS_DIR) -o $@  -L libft -lft -L ft_printf -lftprintf

$(SRCSDIR)/%.o:$(SRCSDIR)/%.c
	cc $(WWW) $(INCLUDES) -o $@ -c $<

clean:
	make -C ./libft/ clean
	make -C ./ft_printf/ clean
	/bin/rm -f $(OBJS_PS_DIR)
	/bin/rm -f $(OBJS_CH_DIR)

fclean: clean
	make -C ./libft/ fclean
	make -C ./ft_printf/ fclean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_PS)

re: fclean all
