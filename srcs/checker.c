/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/12 17:44:27 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				put_to_stack(char *str, t_stack **stack)
{
	long long	num;
	t_stack		*tmp;
	int			str_pos;

	tmp = 0;
	str_pos = 0;
	num = ps_atoi(str, &str_pos);
	if (!(tmp = ft_create_elem(num)) || num > INT_MAX || num < INT_MIN)
		pr_error();
	ft_stack_push_back(stack, tmp);
	return (str_pos);
}

void			parse_multi_args(char *str, t_stack **stack)
{
	while (*str)
		str += put_to_stack(str, stack);
}

char			fill_stack(t_stack **stack, char **argv)
{
	*stack = 0;
	while (*(++argv))
	{
		if (ft_strchr(*argv, ' ') || ft_strchr(*argv, '\t'))/* Add tab etc. */
			parse_multi_args(*argv, stack);
		else if (is_num(*argv))
			put_to_stack(*argv, stack);
		else
			return (0);
	}
	return (1);
}

void		valid_and_sort(t_stack **stack_a)
{
	char	*line;
	t_stack	*stack_b;

	line = 0;
	stack_b = 0;
	while (get_next_line(0, &line) > 0 && *line != 0)
	{
		check_and_do_op(line, stack_a, &stack_b);
		print_stack(*stack_a);
		print_stack(stack_b);
	}
	free(line);
}

int				main(int argc, char **argv)
{
	t_stack		*stack_a;

	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv) && no_duplicates(stack_a))
		{
			print_stack(stack_a);
			valid_and_sort(&stack_a);
			if (check_sort(stack_a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
