/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:27:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/06 19:06:44 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define ALLOWABLE_SYMB "0123456789"

# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_stack
{
	int					num;
	struct s_stack		*next;
	struct s_stack		*prev;

}					t_stack;

typedef struct		s_push_swap
{
	int				size;
	int				size_a;
	int				size_b;
	int				min_a;
	int				max_a;
	int				step_a;
	int				step_b;
	int				oper_a;
	int				oper_b;
	int				cur_elem;
	char			option_print;
	char			option_color;
	t_stack			*stack_a;
	t_stack			*end_a;
	t_stack			*stack_b;
	t_stack			*end_b;

}					t_push_swap;

/*
** ---------------------------- Main Functions ------------------------------
*/

void				*pr_error(t_push_swap *ps);
char				is_num(char *str);
char				fill_stack(t_push_swap *ps, char **argv);
void				parse_multi_args(char *str, t_stack **stack,
															t_push_swap *ps);
int					put_to_stack(char *str, t_stack **stack, t_push_swap *ps);
long long			ps_atoi(const char *str, int *s, t_push_swap *ps);
int					no_duplicates(t_stack *stack);
t_stack				*ft_create_elem(long long num);
void				ft_stack_push_front(t_stack **begin_list, int num,
										t_stack **stack_end, t_push_swap *ps);
void				ft_stack_push_back(t_stack **begin_list, t_stack *cur_elem);
void				valid_and_sort(t_push_swap *ps);
char				check_sort(t_stack *stack);
char				stack_is_empty(t_stack *stack);
void				print_stack(t_stack *stack);
void				print_stacks(char *line, t_push_swap *ps);
void				print_head(char *line, t_push_swap *ps, int *max);
t_stack				*find_stack_end(t_stack *stack);
void				init_stacks_params(t_push_swap *ps);
void				clear_stack(t_stack **stack);
void				clear_stacks(t_push_swap *ps);

/*
** --------------------------- Operations Functions ----------------------------
*/

void				check_and_do_op(char *line, t_push_swap *ps);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_pa(t_push_swap *ps);
void				do_pb(t_push_swap *ps);
void				do_rab(t_stack **stack, t_stack **stack_end);
void				do_ra(t_stack **stack, t_stack **stack_end);
void				do_rb(t_stack **stack, t_stack **stack_end);
void				do_rr(t_push_swap *ps);
void				do_rrab(t_stack **stack, t_stack **stack_end);
void				do_rra(t_stack **stack, t_stack **stack_end);
void				do_rrb(t_stack **stack, t_stack **stack_end);
void				do_rrr(t_push_swap *ps);

/*
** ----------------------------- libft Functions -------------------------------
*/

char				*ft_strchr(const char *s, int c);

#endif
