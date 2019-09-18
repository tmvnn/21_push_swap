/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/18 15:12:58 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			find_sort(t_push_swap *ps)
{
	init_stacks_params(ps);
	if (ps->size == 1)
		return ;
	else if (ps->size == 2)
		sort2(ps);
	else if (ps->size == 3)
		sort3(ps);
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps.stack_a, argv) && (ps.size = no_duplicates(ps.stack_a)))
		{
			init_stacks_params(&ps);
			print_stacks(&ps);
			print_stack_bw(ps.end_a);
			print_stack(ps.stack_b);
			find_sort(&ps);

			print_stacks(&ps);
			print_stack_bw(ps.end_a);
			print_stack(ps.stack_b);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
