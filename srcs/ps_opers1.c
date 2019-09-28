/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:42:54 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/28 17:05:56 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				do_write_sa(t_stack **stack_a)
{
	do_sa(stack_a);
	write(1, "sa\n", 3);
}

void				do_write_sb(t_stack **stack_b)
{
	do_sb(stack_b);
	write(1, "sb\n", 3);
}

void				do_write_pa(t_push_swap *ps)
{
	do_pa(ps);
	write(1, "pa\n", 3);
}

void				do_write_pb(t_push_swap *ps)
{
	do_pb(ps);
	write(1, "pb\n", 3);
}

void				do_write_ra(t_stack **stack, t_stack **stack_end)
{
	do_ra(stack, stack_end);
	write(1, "ra\n", 3);
}
