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

int			find_min_a_el(t_push_swap *ps)
{
	t_stack *tmp;
	int		min;

	min = ps->min_a;
	tmp = ps->stack_a;
	while (tmp)
	{
		if (tmp->num < min)
			return (ps->min_a = tmp->num);
		tmp = tmp->next;
	}
	return (ps->min_a);
}

/*int			n_2_put_in_a(t_push_swap *ps, int cur_n, int *oper)
{
	int		i;
	int		pos;
	t_stack *top_a;
	t_stack *bot_a;

	if ((cur_n < ps->stack_a->num && cur_n > ps->end_a->num) ||
						(ps->stack_a->num == ps->min_a && cur_n < ps->min_a) ||
						(ps->stack_a->num == ps->min_a && cur_n > ps->max_a))//put in fnc
	{
		//printf("HERE\n");
		if (ps->stack_a->num == ps->min_a && cur_n < ps->min_a)
			ps->min_a = cur_n;
		if (ps->stack_a->num == ps->min_a && cur_n > ps->max_a)
			ps->max_a = cur_n;
		*oper = NaN;
		return (0);
	}
	pos = 0;
	i = -1;
	top_a = ps->stack_a->next; //skip first: top_a = ps->stack_a->next;
	bot_a = ps->end_a->prev;
	while (++i <= ps->size_a / 2 )
	{
		if (!top_a->prev && !bot_a->next) // firs iter put outside cycle to optimize
		{

		}
		top_a = top_a->next;
		if (i + 1 <= ps->size_a / 2 - !(ps->size_a % 2)) //Optimize
		{
			bot_a = bot_a->prev;
		}
	}
	return (pos);
}*/

int		handle_bigin_end(t_push_swap *ps, int cur_n, int *oper)
{
	if ((cur_n < ps->stack_a->num && cur_n > ps->end_a->num) ||
						(ps->stack_a->num == ps->min_a && cur_n < ps->min_a) ||
						(ps->stack_a->num == ps->min_a && cur_n > ps->max_a))
	{
		/*if (ps->stack_a->num == ps->min_a && cur_n < ps->min_a)
			ps->min_a = cur_n;
		if (ps->stack_a->num == ps->min_a && cur_n > ps->max_a)
			ps->max_a = cur_n;*/
		*oper = NaN;
		//printf(" from first ");
		return (1);
	}
	return (0);
}

int			set_oper(t_push_swap *ps, int cur_n, int *oper, int i)
{
	if (i <= ps->size_a / 2)
	{
		*oper = ra;
		return (i);
	}
	else
	{
		*oper = rra;
		return (-i + 2 * (ps->size_a / 2) + 1 - (!(ps->size_a % 2))); // i - (i - maxi) - (i - maxi - 1) - !(n % 2nbm )
	}
}

int			n_2_put_in_a(t_push_swap *ps, int cur_n, int *oper)
{
	int		i;
	t_stack *tmp;

	if (handle_bigin_end(ps, cur_n, oper))
		return (0);
	tmp = ps->stack_a->next;
	i = 1;
	while (tmp)
	{
		if (cur_n < tmp->num && cur_n > tmp->prev->num)
		{
			return(set_oper(ps, cur_n, oper, i));
		}
		if (tmp->num == ps->min_a && cur_n < ps->min_a)
		{
			//ps->min_a = cur_n;
			return(set_oper(ps, cur_n, oper, i));
		}
		if (tmp->num == ps->min_a && cur_n > ps->max_a)
		{
			//ps->max_a = cur_n;
			return(set_oper(ps, cur_n, oper, i));
		}
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void		ps_do_op(t_push_swap *ps, int *oper)
{
	if (*oper == ra)
	{

	}
	//do_write_pa(ps);
	*oper = NaN;
}

void		sort_more(t_push_swap *ps)
{
	int		i;
	int		oper_a;
	int		oper_b;
	int		n_top;
	int		n_bot;
	t_stack *top_b;
	t_stack *bot_b;

	if (check_sort(ps->stack_a))
		return ;
	put_all_but3_on_b(ps);
	sort3(ps);
	main_print(ps);



	printf("min_a = %d ",ps->min_a = ps->stack_a->num);
	printf("max_a = %d \n\n",ps->max_a = ps->end_a->num);

	oper_a = NaN;
	oper_b = NaN;
	top_b = ps->stack_b;
	bot_b = ps->end_b;

	//top_b = ps->stack_b;
	i = -1;
	while (++i <= ps->size_b / 2 )
	{
		//printf("min_a = %d ",ps->min_a);
		//printf("max_a = %d ",ps->max_a);
		//i   and   i+1
		n_top = n_2_put_in_a(ps, top_b->num, &oper_a);
		printf("top = %d i = %d n_top = %d oper_a = %d ", top_b->num, i, n_top, oper_a);

		top_b = top_b->next;
		if (i + 1 <= ps->size_b / 2 - !(ps->size_b % 2)) //Optimize
		{
			n_bot = n_2_put_in_a(ps, bot_b->num, &oper_b);
			printf("bot = %d i = %d n_bot = %d oper_b = %d ", bot_b->num, i + 1, n_bot, oper_b);

			bot_b = bot_b->prev;
		}
		//printf("oper_a = %d oper_b = %d", oper_a, oper_b);
		printf("\n");
	}

	ps_do_op(ps, &oper_a);
	main_print(ps);

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
