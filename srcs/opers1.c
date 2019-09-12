/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:50:39 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/12 17:51:12 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_sa(t_stack **stack_a)
{
	int		tmp;

	if (*stack_a != 0 && (*stack_a)->next != 0)
	{
		tmp = (*stack_a)->num;
		(*stack_a)->num = (*stack_a)->next->num;
		(*stack_a)->next->num = tmp;
	}
}

void		do_sb(t_stack **stack_b)
{
	int		tmp;

	if (*stack_b != 0)
		if ((*stack_b)->next != 0)
		{
			tmp = (*stack_b)->num;
			(*stack_b)->num = (*stack_b)->next->num;
			(*stack_b)->next->num = tmp;
		}
}

void		do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}

void		do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a != 0)
	{
		ft_stack_push_front(stack_b, (*stack_a)->num);
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
}

void		do_rab(t_stack **stack)
{
	t_stack	*tmp;
	int		num;

	if (*stack != 0 && (*stack)->next != 0)
	{
		tmp = *stack;
		num = (*stack)->num;
		while (tmp->next)
		{
			tmp->num = tmp->next->num;
			tmp = tmp->next;
		}
		tmp->num = num;
	}
}
