/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/14 20:46:15 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_stack		*stack_a;

	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv) && no_duplicates(stack_a))
		{
			print_stack(stack_a);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
