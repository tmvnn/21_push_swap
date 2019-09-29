/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:01:15 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/29 20:01:17 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NAN 0
# define RA 1
# define RRA 2
# define RB 3
# define RRB 4
# define RR 5
# define RRR 6

# include "checker.h"

typedef struct		s_params
{
	int					oper_a;
	int					oper_b;
	int					step_a;
	int					step_b;
	int					cur_elem;
	int					delta;

}					t_params;

/*
** ---------------------------- Main Functions ------------------------------
*/

void				sort2(t_push_swap *ps);
void				sort3(t_push_swap *ps);
void				sort3_a(t_push_swap *ps);
void				sort_more(t_push_swap *ps);
void				put_all_but3_on_b(t_push_swap *ps);
void				find_optimal_ab_move(t_push_swap *ps);
int					find_pos_in_a(t_push_swap *ps, int cur_n, int *oper);
int					handle_first_and_last(t_push_swap *ps, int cur_n,
																int *oper);
void				do_optimal_ab_move(t_push_swap *ps);
void				switch_to_rr_rrr(t_push_swap *ps);
void				reassign_ps(t_push_swap *ps, t_params par, t_stack *tmp);
void				reassign_a_min_max(t_push_swap *ps);
void				main_print(t_push_swap *ps);
void				rotate_a_to_begin(t_push_swap *ps);

/*
** --------------------------- Operations Functions ----------------------------
*/

void				do_write_sa(t_stack **stack_a);
void				do_write_sb(t_stack **stack_b);
void				do_write_ss(t_stack **stack_a, t_stack **stack_b);
void				do_write_pa(t_push_swap *ps);
void				do_write_pb(t_push_swap *ps);
void				do_write_ra(t_stack **stack, t_stack **stack_end);
void				do_write_rb(t_stack **stack, t_stack **stack_end);
void				do_write_rr(t_push_swap *ps);
void				do_write_rra(t_stack **stack, t_stack **stack_end);
void				do_write_rrb(t_stack **stack, t_stack **stack_end);
void				do_write_rrr(t_push_swap *ps);

/*
** ----------------------------- libft Functions -------------------------------
*/

#endif
