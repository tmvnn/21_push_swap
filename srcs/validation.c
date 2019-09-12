/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:17 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/12 17:44:27 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			*pr_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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

char			no_duplicates(t_stack *stack)
{
	t_stack		*tmp_i;
	t_stack		*tmp_j;

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
		tmp_i = tmp_i->next;
	}
	return (1);
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
