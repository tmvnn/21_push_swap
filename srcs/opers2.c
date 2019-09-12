/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:54:46 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/12 17:55:12 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_ra(t_stack **stack)
{
	do_rab(stack);
}

void		do_rb(t_stack **stack)
{
	do_rab(stack);
}

void		do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_rab(stack_a);
	do_rab(stack_b);
}

void		do_rrab(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack != 0 && (*stack)->next != 0)
	{
		tmp = *stack;
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}
		tmp->next->next = *stack;
		*stack = tmp->next;
		tmp->next = 0;
	}
}

void		do_rra(t_stack **stack)
{
	do_rrab(stack);
}
