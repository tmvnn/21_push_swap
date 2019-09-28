/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/28 19:39:53 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		switch_to_rr_rrr(t_push_swap *ps)
{
	int		i;

	if (ps->oper_b == RB && ps->oper_a == RA)
	{
		i = ps->step_b < ps->step_a ? ps->step_b : ps->step_a;
		ps->step_b -= i;
		ps->step_a -= i;
		while (i--)
			do_write_rr(ps);
	}
	else if (ps->oper_b == RRB && ps->oper_a == RRA)
	{
		i = ps->step_b < ps->step_a ? ps->step_b : ps->step_a;
		ps->step_b -= i;
		ps->step_a -= i;
		while (i--)
			do_write_rrr(ps);
	}
}

void		do_optimal_ab_move(t_push_swap *ps)
{
	int		i;

	switch_to_rr_rrr(ps);
	i = -1;
	if (ps->oper_b == RB)
		while (++i < ps->step_b)
			do_write_rb(&ps->stack_b, &ps->end_b);
	i = -1;
	if (ps->oper_b == RRB)
		while (++i < ps->step_b)
			do_write_rrb(&ps->stack_b, &ps->end_b);
	if (ps->oper_a == RA)
	{
		i = -1;
		while (++i < ps->step_a)
			do_write_ra(&ps->stack_a, &ps->end_a);
	}
	if (ps->oper_a == RRA)
	{
		i = -1;
		while (++i < ps->step_a)
			do_write_rra(&ps->stack_a, &ps->end_a);
	}
	do_write_pa(ps);
}

void		rotate_a_to_begin(t_push_swap *ps)
{
	t_stack *tmp;
	int		min;
	int		i;

	min = ps->min_a;
	tmp = ps->stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->num == min)
		{
			if (i <= ps->size_a / 2)
				while (i--)
					do_write_ra(&ps->stack_a, &ps->end_a);
			else
			{
				i = -i + 2 * (ps->size_a / 2) + 1 - (!(ps->size_a % 2));
				while (i--)
					do_write_rra(&ps->stack_a, &ps->end_a);
			}
			return ;
		}
		tmp = tmp->next;
		i++;
	}
}

void		reassign_a_min_max(t_push_swap *ps)
{
	if (ps->cur_elem < ps->min_a)
		ps->min_a = ps->cur_elem;
	else if (ps->cur_elem > ps->max_a)
		ps->max_a = ps->cur_elem;
}

void		sort_more(t_push_swap *ps)
{
	if (check_sort(ps->stack_a))
		return ;
	put_all_but3_on_b(ps);
	sort3(ps);
	ps->min_a = ps->stack_a->num;
	ps->max_a = ps->end_a->num;
	while (ps->stack_b)
	{
		find_optimal_ab_move(ps);
		reassign_a_min_max(ps);
		do_optimal_ab_move(ps);
	}
	rotate_a_to_begin(ps);
}
