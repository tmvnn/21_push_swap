/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/08 18:35:57 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*pr_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

t_stack		*ft_create_elem(long long num)
{
	t_stack	*newlist;

	if ((newlist = (t_stack*)malloc(sizeof(t_stack))))
	{
		newlist->next = 0;
		newlist->num = (int)num;
	}
	return (newlist);
}

void		ft_stack_push_back(t_stack **begin_list, t_stack *cur_elem)
{
	t_stack	*tmpptr;

	if (*begin_list == 0)
		*begin_list = cur_elem;
	else
	{
		tmpptr = *begin_list;
		while (tmpptr->next)
			tmpptr = tmpptr->next;
		tmpptr->next = cur_elem;
	}
}

void	ft_stack_push_front(t_stack **begin_list, int num)
{
	t_stack *new;

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

char		is_num(char *str)
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

int				put_to_stack(char *str, t_stack **stack)
{
	long long 	num;
	t_stack 	*tmp;
	int			str_pos;

	tmp = 0;
	str_pos = 0;
	num = ps_atoi(str, &str_pos);
	if (!(tmp = ft_create_elem(num)) || num > INT_MAX || num < INT_MIN)
		pr_error();
	ft_stack_push_back(stack, tmp);
	return (str_pos);
}

void		parse_multi_args(char *str, t_stack **stack)
{
	while (*str)
		str += put_to_stack(str, stack);
}

char		fill_stack(t_stack **stack, char **argv)
{
	*stack = 0;
	while (*(++argv))
	{
		if (ft_strchr(*argv, ' ') || ft_strchr(*argv, '\t')) // Add tab etc.
		{	
			parse_multi_args(*argv, stack);
		}
		else if (is_num(*argv))
		{
			put_to_stack(*argv, stack);
		}
		else
			return (0);
	}
	return (1);
}

void 		print_stack(t_stack *stack)
{
	t_stack 	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	t_stack		*stack_a;

	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv))
		{
			print_stack(stack_a);
			valid_and_sort(&stack_a);
			//print_stack(stack_a);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
