/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/18 16:13:25 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort2(t_push_swap *ps)
{
	if (ps->stack_a->num > ps->stack_a->next->num)
		write(1, "sa\n", 3);
}

void		sort3(t_push_swap *ps)
{
	t_stack	*t;
	t_stack	*m;
	t_stack	*b;

	if (check_sort(ps->stack_a))
		return ;
	t = ps->stack_a;
	m = ps->stack_a->next;
	b = ps->stack_a->next->next;
	if (t->num > m->num && t->num < b->num)
		do_write_sa(&ps->stack_a);
	else if (t->num > m->num && t->num > b->num && m->num > b->num)
	{
		do_write_sa(&ps->stack_a);
		do_write_rra(&ps->stack_a, &ps->end_a);
	}
	else if (t->num > m->num && t->num > b->num && m->num < b->num)
		do_write_ra(&ps->stack_a, &ps->end_a);
	else if (t->num < m->num && t->num < b->num)
	{
		do_write_sa(&ps->stack_a);
		do_write_ra(&ps->stack_a, &ps->end_a);
	}
	else
		do_write_rra(&ps->stack_a, &ps->end_a);
}
