/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:24:41 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/16 23:00:41 by timuryakubo      ###   ########.fr       */
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

void			ft_stack_push_front(t_stack **begin_list, int num, t_stack **stack_end)
{
	t_stack		*new;

	if (!(new = ft_create_elem(num)))
		pr_error();
	if (*begin_list == 0)
	{
		new->next = 0;
		*begin_list = new;
		*stack_end = new;
	}
	else
	{
		new->next = *begin_list;
		(*begin_list)->prev = new;
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

void			print_stack_bw(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->prev;
	}
	printf("\n");
}

t_stack			*find_stack_end(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (!tmp->next)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}

void			print_stacks(t_push_swap *ps)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	int			max;

	printf(" ___________________________ \n");
	printf("|             |             |\n");
	printf("|      a      |      b      |\n");
	printf("|_____________|_____________|\n");
	max = ps->size_a > ps->size_b ? ps->size_a : ps->size_b;
	tmp_a = ps->stack_a;
	tmp_b = ps->stack_b;
	while (max--)
	{
		if (tmp_a)
		{
			printf("| %-12d", tmp_a->num);
			tmp_a = tmp_a->next;
		}
		else
			printf("|             ");
		if (tmp_b)
		{
			printf("| %-12d|\n", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		else
			printf("|             |\n");
	}
	printf("|_____________|_____________|\n");
}
