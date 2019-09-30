/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:04:03 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/30 21:50:54 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			valid_and_sort(t_push_swap *ps)
{
	char	*line;

	line = 0;
	init_stacks_params(ps);
	while (get_next_line(0, &line) == 1)
	{
		check_and_do_op(line, ps);
		if (ps->option_print)
			print_stacks(line, ps);
		free(line);
	}
	free(line);
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps, argv) &&
										(ps.size = no_duplicates(ps.stack_a)))
		{
			valid_and_sort(&ps);
			if (check_sort(ps.stack_a) && !stack_is_empty(ps.stack_b))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			clear_stacks(&ps);
		}
		else
			return ((int)pr_error(&ps));
	}
	return (0);
}
