/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:41:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/15 22:51:54 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_rra(t_stack **stack)
{
	do_rrab(stack);
}

void		do_rrb(t_stack **stack)
{
	do_rrab(stack);
}

void		do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rrab(stack_a);
	do_rrab(stack_b);
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
		do_ra(&ps->stack_a);
	else if (!ft_strcmp(line, "rb"))
		do_rb(&ps->stack_b);
	else if (!ft_strcmp(line, "rr"))
		do_rr(&ps->stack_a, &ps->stack_b);
	else if (!ft_strcmp(line, "rra"))
		do_rra(&ps->stack_a);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(&ps->stack_b);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(&ps->stack_a, &ps->stack_b);
	else
		pr_error();
}
