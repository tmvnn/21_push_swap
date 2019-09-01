/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/01 21:21:57 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*pr_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

t_stack		*ft_create_elem(int num)
{
	t_stack	*newlist;

	if ((newlist = (t_stack*)malloc(sizeof(t_stack))))
	{
		newlist->next = NULL;
		newlist->num = num;
	}
	return (newlist);
}

void		ft_stack_push_back(t_stack **begin_list, t_stack *cur_elem)
{
	t_stack	*tmpptr;

	if (*begin_list == NULL)
		*begin_list = cur_elem;
	else
	{
		tmpptr = *begin_list;
		while (tmpptr->next)
			tmpptr = tmpptr->next;
		tmpptr->next = cur_elem;
	}
}

char		is_num(char *str)
{
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
			return (0);
	}
	return (1);
}

char		fill_stack(t_stack **stack, char **argv)
{
	int 	num;
	t_stack *tmp;
	char 	*str;

	num = 0;
	tmp = 0;
	*stack = 0;
	while (*(++argv))
	{
		str = *argv;
		//if (ft_strchr(*argv, ' '))

		if (is_num(str))
		{
			num = ft_atoi(str);
			if (!(tmp = ft_create_elem(num)))
				return ((char)pr_error());
			ft_stack_push_back(stack, tmp);
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
	char		t[6];
	t_stack		*stack;

	if (argc > 1)
	{
		if (fill_stack(&stack, argv))
		{
			
			print_stack(stack);
		}
		else
			return ((int)pr_error());
		

		//if (read(0, t, 6))
			//printf("Exist = %s\n", t);
	}
	return (0);
}
