/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/19 21:35:49 by timuryakubo      ###   ########.fr       */
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

void		put_all_but3_on_b(t_push_swap *ps)
{
	int		i;

	i = -1;
	while(++i < ps->size - 3)
		do_write_pb(ps);
}

int			n_2_put_in_a(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		tmp = tmp->next;
	}
	return (1);
}

void		sort_more(t_push_swap *ps)
{
	int		i;
	t_stack *min;
	t_stack *top_b;
	t_stack *bot_b;

	if (check_sort(ps->stack_a))
		return ;
	put_all_but3_on_b(ps);
	sort3_a(ps);

	main_print(ps);
	i = -1;
	top_b = ps->stack_b;
	bot_b = ps->end_b;
	printf("size_b = %d\n", ps->size_b);
	while (++i <= ps->size_b / 2 )
	{
		//i   and   i+1
		top_b = top_b->next;
		if (i + 1 <= ps->size_b / 2 - !(ps->size_b % 2))
		{
			//printf("bot = %d ", bot_b->num);
			bot_b = bot_b->prev;
		}
		printf("\n");
	}

	/*do_write_ra(&ps->stack_a, &ps->end_a); //./push_swap 5 12 18 4 7 1 9 2 10 11 20 6 13
	do_write_pa(ps);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rb(&ps->stack_b, &ps->end_b);
	do_write_pa(ps);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rb(&ps->stack_b, &ps->end_b);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	//
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_rra(&ps->stack_a, &ps->end_a);*/

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
