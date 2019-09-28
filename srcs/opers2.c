/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:54:46 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/28 17:06:41 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_rab(t_stack **stack, t_stack **stack_end)
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
		*stack_end = *stack;
		(*stack)->next->prev = 0;
		(*stack)->prev = tmp->next;
		tmp = (*stack)->next;
		(*stack)->next = 0;
		*stack = tmp;
	}
}

void		do_ra(t_stack **stack, t_stack **stack_end)
{
	do_rab(stack, stack_end);
}

void		do_rb(t_stack **stack, t_stack **stack_end)
{
	do_rab(stack, stack_end);
}

void		do_rr(t_push_swap *ps)
{
	do_rab(&ps->stack_a, &ps->end_a);
	do_rab(&ps->stack_b, &ps->end_b);
}

void		do_rrab(t_stack **stack, t_stack **stack_end)
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
		tmp->next->prev = 0;
		(*stack)->prev = tmp->next;
		*stack = tmp->next;
		tmp->next = 0;
		*stack_end = tmp;
	}
}
