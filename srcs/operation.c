/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:41:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/12 17:55:25 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_rrb(t_stack **stack)
{
	do_rrab(stack);
}

void		do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rrab(stack_a);
	do_rrab(stack_b);
}

void		check_and_do_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa"))
		do_sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		do_sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		do_ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		do_pb(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb"))
		do_pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		do_ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		do_rb(stack_b);
	else if (!ft_strcmp(line, "rr"))
		do_rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra"))
		do_rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(stack_b);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(stack_a, stack_b);
	else
		pr_error();
}
