/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:17:17 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/24 13:45:54 by timuryakubo      ###   ########.fr       */
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

void		do_op_with_min_step(t_push_swap *ps)
{
	int		i;

	if (ps->oper_b == rb)
	{
		i = -1;
		while (++i < ps->step_b)
		{
			do_write_rb(&ps->stack_b, &ps->end_b);
		}
	}
	if (ps->oper_b == rrb)
	{
		i = -1;
		while (++i < ps->step_b)
		{
			do_write_rrb(&ps->stack_b, &ps->end_b);
		}
	}
	if (ps->oper_a  == ra)
	{
		i = -1;
		while (++i < ps->step_a)
		{
			do_write_ra(&ps->stack_a, &ps->end_a);
		}
	}
	if (ps->oper_a  == rra)
	{
		i = -1;
		while (++i < ps->step_a)
		{
			do_write_rra(&ps->stack_a, &ps->end_a);
		}
	}
	do_write_pa(ps);
}

int 	min_step(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

void		rotate_a_to_begin(t_push_swap *ps)
{
	t_stack *tmp;
	int		min;
	int		i;

	min = ps->min_a;
	tmp = ps->stack_a;
	i = 0;
	while (tmp)
	{
		if (tmp->num == min)
		{
			if (i <= ps->size_a / 2)
			{
				while (i--)
					do_write_ra(&ps->stack_a, &ps->end_a);
				return ;
			}
			else
			{
				i = -i + 2 * (ps->size_a / 2) + 1 - (!(ps->size_a % 2));
				while (i--)
					do_write_rra(&ps->stack_a, &ps->end_a);
				return ;
			}
		}
		tmp = tmp->next;
		i++;
	}
}

void		sort_more(t_push_swap *ps)
{
	int		i;
	int		oper_a;
	int		oper_b;
	int		step_a;
	int		step_b;
	int		min_a;
	int		max_a;
	int		delta;
	t_stack *tmp;

	if (check_sort(ps->stack_a))
		return ;
	put_all_but3_on_b(ps);
	sort3(ps);
	//main_print(ps);




	ps->min_a = ps->stack_a->num;
	ps->max_a = ps->end_a->num;
	/*do_write_pa(ps);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_ra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_rra(&ps->stack_a, &ps->end_a);
	do_write_pa(ps);
	do_write_pa(ps);
	main_print(ps);*/
	min_a = ps->stack_a->num;
	max_a = ps->end_a->num;
	while (ps->stack_b)
	{
		//printf("min_a = %d ",ps->min_a);
		//printf("max_a = %d \n\n",ps->max_a);
		i = 0;
		tmp = ps->stack_b;
		delta = 2 * (ps->size_b / 2) + 1 - (!(ps->size_b % 2));
		oper_a = NaN;
		oper_b = NaN;
		ps->step_a = INT_MAX; //check for long long
		ps->step_b = 0;
		while (tmp)
		{
			//i   and   i+1
			step_a = n_2_put_in_a(ps, tmp->num, &oper_a);
			step_b = (i <= ps->size_b / 2) ? i : (-i + delta);
			oper_b = (i <= ps->size_b / 2) ? rb : rrb;
			//printf("tmp->num = %d   step_a = %d   step_b = %d   oper_a = %d   oper_b = %d \n", tmp->num, step_a, step_b, oper_a, oper_b);


			if (step_a + step_b < ps->step_a + ps->step_b)
			{
				ps->step_a = step_a;
				ps->step_b = step_b;
				ps->oper_a = oper_a;
				ps->oper_b = oper_b;
				if (tmp->num < ps->min_a)
					min_a = tmp->num;
				if (tmp->num > ps->max_a)
					max_a = tmp->num;
			}
			if (step_a + step_b  <= i + 1)
				break;
			////printf("tmp->num = %d step_a = %d step_b = %d oper_a = %d oper_b = %d \n", tmp->num, ps->step_a, ps->step_b, ps->oper_a, ps->oper_b);

			i++;
			tmp = tmp->next;
		}
		//printf("\n");
		ps->min_a = min_a;
		ps->max_a = max_a;
		do_op_with_min_step(ps);
		//main_print(ps);
	}
	printf("min_a = %d\n",ps->min_a);
	main_print(ps);
	rotate_a_to_begin(ps);
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
