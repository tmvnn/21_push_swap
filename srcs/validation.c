/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:17 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/29 20:19:01 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			*pr_error(t_push_swap *ps)
{
	write(1, "Error\n", 6);
	clear_stacks(ps);
	exit(1);
}

void			clear_stacks(t_push_swap *ps)
{
	clear_stack(&ps->stack_a);
	clear_stack(&ps->stack_b);
}

char			is_num(char *str)
{
	while (*str)
	{
		if ((*str >= 48 && *str <= 57) || *str == '+' || *str == '-')
			str++;
		else
			return (0);
	}
	return (1);
}

int				no_duplicates(t_stack *stack)
{
	t_stack		*tmp_i;
	t_stack		*tmp_j;
	int			size;

	size = 0;
	tmp_i = stack;
	while (tmp_i)
	{
		if (tmp_i->next)
		{
			tmp_j = tmp_i->next;
			while (tmp_j)
			{
				if (tmp_i->num == tmp_j->num)
				{
					return (0);
				}
				tmp_j = tmp_j->next;
			}
		}
		size++;
		tmp_i = tmp_i->next;
	}
	return (size);
}

char			check_sort(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->num > tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
