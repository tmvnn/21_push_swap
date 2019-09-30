/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_opt_ab_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/30 21:29:00 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				handle_first_and_last(t_push_swap *ps, int cur_n, int *oper)
{
	if ((cur_n < ps->stack_a->num && cur_n > ps->end_a->num) ||
						(ps->stack_a->num == ps->min_a && cur_n < ps->min_a) ||
						(ps->stack_a->num == ps->min_a && cur_n > ps->max_a))
	{
		*oper = NAN;
		return (1);
	}
	return (0);
}

int				set_oper(t_push_swap *ps, int *oper, int i)
{
	if (i <= ps->size_a / 2)
	{
		*oper = RA;
		return (i);
	}
	else
	{
		*oper = RRA;
		return (-i + 2 * (ps->size_a / 2) + 1 - (!(ps->size_a % 2)));
	}
}

int				find_pos_in_a(t_push_swap *ps, int cur_n, int *oper)
{
	int			i;
	t_stack		*tmp;

	*oper = NAN;
	if (handle_first_and_last(ps, cur_n, oper))
		return (0);
	tmp = ps->stack_a->next;
	i = 1;
	while (tmp)
	{
		if (cur_n < tmp->num && cur_n > tmp->prev->num)
			return (set_oper(ps, oper, i));
		if (tmp->num == ps->min_a && cur_n < ps->min_a)
			return (set_oper(ps, oper, i));
		if (tmp->num == ps->min_a && cur_n > ps->max_a)
			return (set_oper(ps, oper, i));
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void			reassign_ps(t_push_swap *ps, t_params par, t_stack *tmp)
{
	ps->step_a = par.step_a;
	ps->step_b = par.step_b;
	ps->oper_a = par.oper_a;
	ps->oper_b = par.oper_b;
	ps->cur_elem = tmp->num;
}

void			find_optimal_ab_move(t_push_swap *ps)
{
	int			i;
	t_stack		*tmp;
	t_params	par;

	i = 0;
	tmp = ps->stack_b;
	par.delta = 2 * (ps->size_b / 2) + 1 - (!(ps->size_b % 2));
	ps->step_a = INT_MAX;
	ps->step_b = 0;
	while (tmp)
	{
		par.step_a = find_pos_in_a(ps, tmp->num, &par.oper_a);
		par.step_b = (i <= ps->size_b / 2) ? i : (-i + par.delta);
		par.oper_b = (i <= ps->size_b / 2) ? RB : RRB;
		if (par.step_a + par.step_b < ps->step_a + ps->step_b)
			reassign_ps(ps, par, tmp);
		i++;
		tmp = tmp->next;
	}
}
