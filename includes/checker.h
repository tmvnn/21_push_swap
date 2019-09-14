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

#ifndef CHECKER_H
# define CHECKER_H

# define ALLOWABLE_SYMB "0123456789"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_stack
{
	int					num;
	struct s_stack		*next;

}					t_stack;

/*
** ---------------------------- Main Functions ------------------------------
*/

void				*pr_error(void);
char				is_num(char *str);
char				fill_stack(t_stack **stack, char **argv);
void				parse_multi_args(char *str, t_stack **stack);
int					put_to_stack(char *str, t_stack **stack);
long long			ps_atoi(const char *str, int *s);
char				no_duplicates(t_stack *stack);
t_stack				*ft_create_elem(long long num);
void				ft_stack_push_front(t_stack **begin_list, int num);
void				ft_stack_push_back(t_stack **begin_list, t_stack *cur_elem);
void				valid_and_sort(t_stack **stack_a, t_stack **stack_b);
char				check_sort(t_stack *stack);
char				stack_is_empty(t_stack *stack);
void 				print_stack(t_stack *stack);

/*
** --------------------------- Operations Functions ----------------------------
*/

void				check_and_do_op(char *line, t_stack **stack_a, t_stack **stack_b);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
void				do_rab(t_stack **stack);
void				do_ra(t_stack **stack);
void				do_rb(t_stack **stack);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rrab(t_stack **stack);
void				do_rra(t_stack **stack);
void				do_rrb(t_stack **stack);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

/*
** ----------------------------- libft Functions -------------------------------
*/

char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);

#endif
