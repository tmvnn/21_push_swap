/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:22:41 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/17 23:28:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FT_MIN(a,b) ((a)>(b)?(b):(a))
# define NaN 0
# define ra 1
# define rra 2
# define rb 3
# define rrb 4
# define rr 5
# define rrr 6

# include "checker.h"

typedef struct		s_params
{
	int					i_top;
	int					i_bot;
	struct s_params		*next;
	struct s_params		*prev;

}					t_params;

/*
** ---------------------------- Main Functions ------------------------------
*/

void				sort2(t_push_swap *ps);
void				sort3(t_push_swap *ps);
void				sort3_a(t_push_swap *ps);
void				sort_more(t_push_swap *ps);
void				put_all_but3_on_b(t_push_swap *ps);
void				main_print(t_push_swap *ps); //DELELTE!
int 				min_step(int n1, int n2);

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
