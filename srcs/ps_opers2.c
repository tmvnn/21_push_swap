/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:42:54 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/28 17:09:21 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				do_write_rb(t_stack **stack, t_stack **stack_end)
{
	do_rb(stack, stack_end);
	write(1, "rb\n", 3);
}

void				do_write_rr(t_push_swap *ps)
{
	do_rr(ps);
	write(1, "rr\n", 3);
}

void				do_write_rra(t_stack **stack, t_stack **stack_end)
{
	do_rra(stack, stack_end);
	write(1, "rra\n", 4);
}

void				do_write_rrb(t_stack **stack, t_stack **stack_end)
{
	do_rrb(stack, stack_end);
	write(1, "rrb\n", 4);
}

void				do_write_rrr(t_push_swap *ps)
{
	do_rrr(ps);
	write(1, "rrr\n", 4);
}
