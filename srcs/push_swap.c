/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/15 18:33:06 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*find_stack_end(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		//printf("%d ", tmp->num);
		tmp = tmp->next;
		if (!tmp->next)
		{
			return (tmp);
		}
	}
	return (0);
}

void			print_stack_from_end(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->num);
		//printf("\033[31m%d \033[m", tmp->num);
		tmp = tmp->prev;
	}
	printf("\n");
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps.stack_a, argv) && (ps.size = no_duplicates(ps.stack_a)))
		{
			print_stack(ps.stack_a);
			print_stack_from_end(find_stack_end(ps.stack_a));
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
