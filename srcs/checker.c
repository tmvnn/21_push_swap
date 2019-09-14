/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/14 20:42:48 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			valid_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = 0;
	*stack_b = 0;
	while (get_next_line(0, &line) > 0 && *line != 0)
	{
		check_and_do_op(line, stack_a, stack_b);
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
	free(line);
}

int				main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv) && no_duplicates(stack_a))
		{
			print_stack(stack_a);
			valid_and_sort(&stack_a, &stack_b);
			if (check_sort(stack_a) && !stack_is_empty(stack_b))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
