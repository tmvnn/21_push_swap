/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/18 17:30:52 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort2(t_push_swap *ps)
{
	if (ps->stack_a->num > ps->stack_a->next->num)
		write(1, "sa\n", 3);
}

void		sort3_a(t_push_swap *ps)
{
	int	t;
	int m;
	int b;

	t = ps->stack_a->num;
	m = ps->stack_a->next->num;
	b = ps->stack_a->next->next->num;
	if (t > m && t < b)
		do_write_sa(&ps->stack_a);
	else if (t > m && t > b && m > b)
	{
		do_write_sa(&ps->stack_a);
		do_write_rra(&ps->stack_a, &ps->end_a);
	}
	else if (t > m && t > b && m < b)
		do_write_ra(&ps->stack_a, &ps->end_a);
	else if (t < m && t < b)
	{
		do_write_sa(&ps->stack_a);
		do_write_ra(&ps->stack_a, &ps->end_a);
	}
	else
		do_write_rra(&ps->stack_a, &ps->end_a);
}

void		sort3(t_push_swap *ps)
{
	if (check_sort(ps->stack_a))
		return ;
	sort3_a(ps);
}

void		sort_more(t_push_swap *ps)
{
	/*do_write_sa(&ps->stack_a); //./push_swap 2 1 3 6 5 8
	do_write_pb(ps);
	do_write_pb(ps);
	do_write_pb(ps);
	do_write_rr(ps);
	do_write_rrr(ps);
	do_write_sa(&ps->stack_a);
	do_write_pa(ps);
	do_write_pa(ps);
	do_write_pa(ps);*/

	/*do_write_pb(ps); //./push_swap 1 5 2 4 3
	do_write_pb(ps);
	do_write_sa(&ps->stack_a);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);*/
}
