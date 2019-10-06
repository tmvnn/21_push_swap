/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:24:41 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/10/06 19:07:57 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			print_stack(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	ft_printf("\n");
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
			ft_printf("\033[32m%s:\033[m\n", line);
		else
			ft_printf("\033[31m%s:\033[m\n", line);
	}
	*max = ps->size_a > ps->size_b ? ps->size_a : ps->size_b;
	ft_printf(" ___________________________ \n");
	ft_printf("|             |             |\n");
	ft_printf("|      a      |      b      |\n");
	ft_printf("|_____________|_____________|\n");
}

void			print_rest(t_push_swap *ps, t_stack *tmp_a, t_stack *tmp_b,
																		int max)
{
	while (max--)
	{
		if (tmp_a)
		{
			ps->option_color ? ft_printf("|  \033[32m%-11d\033[m", tmp_a->num) :
											ft_printf("|  %-11d", tmp_a->num);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("|             ");
		if (tmp_b)
		{
			ps->option_color ? ft_printf("|  \033[31m%-11d\033[m|\n",
						tmp_b->num) : ft_printf("|  %-11d|\n", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("|             |\n");
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
	ft_printf("|_____________|_____________|\n\n");
}
