/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:24:41 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/15 17:49:32 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack			*ft_create_elem(long long num)
{
	t_stack		*newlist;

	if ((newlist = (t_stack*)malloc(sizeof(t_stack))))
	{
		newlist->next = 0;
		newlist->prev = 0;
		newlist->num = (int)num;
	}
	return (newlist);
}

void			ft_stack_push_back(t_stack **begin_list, t_stack *cur_elem)
{
	t_stack		*tmpptr;

	if (*begin_list == 0)
		*begin_list = cur_elem;
	else
	{
		tmpptr = *begin_list;
		while (tmpptr->next)
			tmpptr = tmpptr->next;
		tmpptr->next = cur_elem;
		cur_elem->prev = tmpptr;
	}
}

void			ft_stack_push_front(t_stack **begin_list, int num)
{
	t_stack		*new;

	if (!(new = ft_create_elem(num)))
		pr_error();
	if (*begin_list == 0)
	{
		new->next = 0;
		*begin_list = new;
	}
	else
	{
		new->next = *begin_list;
		*begin_list = new;
	}
}

char			stack_is_empty(t_stack *stack)
{
	if (stack)
		return (1);
	else
		return (0);
}

void			print_stack(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}
