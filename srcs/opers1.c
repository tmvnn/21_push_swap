/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:50:39 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/15 21:34:55 by lbellona         ###   ########.fr       */
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

void		do_pb(t_push_swap *ps)
{
	t_stack	*tmp;

	if (ps->stack_a != 0)
	{
		ft_stack_push_front(&ps->stack_b, ps->stack_a->num);
		tmp = ps->stack_a->next;
		free(ps->stack_a);
		ps->stack_a = tmp;
		ps->size_a--;
		ps->size_b++;
	}
}

void		do_pa(t_push_swap *ps)
{
	t_stack	*tmp;

	if (ps->stack_b != 0)
	{
		ft_stack_push_front(&ps->stack_a, ps->stack_b->num);
		tmp = ps->stack_b->next;
		free(ps->stack_b);
		ps->stack_b = tmp;
		ps->size_a++;
		ps->size_b--;
	}
}
