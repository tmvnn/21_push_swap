/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/24 16:56:22 by timuryakubo      ###   ########.fr       */
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
		sort3(ps);\
	else
	{
		sort_more(ps);
	}

}

void			main_print(t_push_swap *ps)
{
	//print_stacks(ps);
	//print_stack_bw(ps->end_a);
	print_stack(ps->stack_a);
	print_stack(ps->stack_b);
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps.stack_a, argv) && (ps.size = no_duplicates(ps.stack_a)))
		{
			init_stacks_params(&ps);
			//main_print(&ps);
			find_sort(&ps);
			//main_print(&ps);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
