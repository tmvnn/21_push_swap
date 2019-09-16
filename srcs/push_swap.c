/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/16 21:47:48 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack			*find_stack_end(t_stack *stack)
// {
// 	t_stack		*tmp;

// 	tmp = stack;
// 	while (tmp)
// 	{
// 		//printf("%d ", tmp->num);
// 		tmp = tmp->next;
// 		if (!tmp->next)
// 		{
// 			return (tmp);
// 		}
// 	}
// 	return (0);
// }

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps.stack_a, argv) && (ps.size = no_duplicates(ps.stack_a)))
		{
			print_stack(ps.stack_a);

		}
		else
			return ((int)pr_error());
	}
	return (0);
}
