/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:41:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/08 20:28:44 by lbellona         ###   ########.fr       */
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

void		valid_and_sort(t_stack **stack_a)
{
	char	*line;
	t_stack	*stack_b;

	line = 0;
	stack_b = 0;
	while (get_next_line(0, &line) > 0 && *line != 0)
	{
		check_and_do_op(line, stack_a, &stack_b);
		print_stack(*stack_a);
		print_stack(stack_b);
	}
	free(line);
}
