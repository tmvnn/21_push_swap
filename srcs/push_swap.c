/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/28 17:07:55 by lbellona         ###   ########.fr       */
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
	else
		sort_more(ps);
}

void			main_print(t_push_swap *ps)
{
	print_stack(ps->stack_a);
	print_stack(ps->stack_b);
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps, argv) && (ps.size = no_duplicates(ps.stack_a)))
		{
			init_stacks_params(&ps);
			find_sort(&ps);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
