/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:24:41 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/28 19:06:50 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_stack			*find_stack_end(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

void			print_head(char *line, t_push_swap *ps, int *max)
{
	if (*line != 0)
	{
		if (ft_strchr(line, 'a'))
			printf("\033[32m%s:\033[m\n", line);
		else
			printf("\033[31m%s:\033[m\n", line);
	}
	*max = ps->size_a > ps->size_b ? ps->size_a : ps->size_b;
	printf(" ___________________________ \n");
	printf("|             |             |\n");
	printf("|      a      |      b      |\n");
	printf("|_____________|_____________|\n");
}

void			print_rest(t_push_swap *ps, t_stack *tmp_a, t_stack *tmp_b,
																		int max)
{
	while (max--)
	{
		if (tmp_a)
		{
			ps->option_color ? printf("|  \033[32m%-11d\033[m", tmp_a->num) :
											printf("|  %-11d", tmp_a->num);
			tmp_a = tmp_a->next;
		}
		else
			printf("|             ");
		if (tmp_b)
		{
			ps->option_color ? printf("|  \033[31m%-11d\033[m|\n", tmp_b->num) :
											printf("|  %-11d|\n", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		else
			printf("|             |\n");
	}
}

void			print_stacks(char *line, t_push_swap *ps)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	int			max;

	print_head(line, ps, &max);
	tmp_b = ps->stack_b;
	tmp_a = ps->stack_a;
	print_rest(ps, tmp_a, tmp_b, max);
	printf("|_____________|_____________|\n\n");
}
