/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:41:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/07 20:03:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sa(t_stack **stack_a)
{
	int		tmp;
	
	if (*stack_a != 0 && (*stack_a)->next != 0)
	{
		tmp = (*stack_a)->num;
		(*stack_a)->num = (*stack_a)->next->num;
		(*stack_a)->next->num = tmp;
	}
}

void	do_sb(t_stack **stack_b)
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

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
}

void	check_and_do_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa"))
		do_sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		do_sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		do_ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		printf("pa");
	else if (!ft_strcmp(line, "pb"))
		do_pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		printf("ra");
	else if (!ft_strcmp(line, "rb"))
		printf("rb");
	else if (!ft_strcmp(line, "rr"))
		printf("rr");
	else if (!ft_strcmp(line, "rra"))
		printf("rra");
	else if (!ft_strcmp(line, "rrb"))
		printf("rrb");
	else if (!ft_strcmp(line, "rrr"))
		printf("rrr");
	else
		pr_error();
}

void	valid_and_sort(t_stack **stack_a)
{
	char		*line;
	t_stack		*stack_b;

	line = 0;
	stack_b = 0;
	while (get_next_line(0, &line) > 0 && *line != 0)
	{
		check_and_do_op(line, stack_a, &stack_b);
		//printf("Exit = '%s'\n", line);
	}
	free(line);
}