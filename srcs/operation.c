/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:41:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/17 21:38:43 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_rra(t_stack **stack, t_stack **stack_end)
{
	do_rrab(stack, stack_end);
}

void		do_rrb(t_stack **stack, t_stack **stack_end)
{
	do_rrab(stack, stack_end);
}

void		do_rrr(t_push_swap *ps)
{
	do_rrab(&ps->stack_a, &ps->end_a);
	do_rrab(&ps->stack_b, &ps->end_b);
}

void		check_and_do_op(char *line, t_push_swap *ps)
{
	if (!ft_strcmp(line, "sa"))
		do_sa(&ps->stack_a);
	else if (!ft_strcmp(line, "sb"))
		do_sb(&ps->stack_b);
	else if (!ft_strcmp(line, "ss"))
		do_ss(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(line, "pa"))
		do_pa(ps);
	else if (!ft_strcmp(line, "pb"))
		do_pb(ps);
	else if (!ft_strcmp(line, "ra"))
		do_ra(&ps->stack_a, &ps->end_a);
	else if (!ft_strcmp(line, "rb"))
		do_rb(&ps->stack_b, &ps->end_b);
	else if (!ft_strcmp(line, "rr"))
		do_rr(ps);
	else if (!ft_strcmp(line, "rra"))
		do_rra(&ps->stack_a, &ps->end_a);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(&ps->stack_b, &ps->end_b);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(ps);
	else
		pr_error();
}
