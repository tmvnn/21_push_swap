/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:17:45 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/29 17:02:03 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			init_stacks_params(t_push_swap *ps)
{
	ps->size_a = ps->size;
	ps->size_b = 0;
	ps->stack_b = 0;
	ps->end_a = find_stack_end(ps->stack_a);
	ps->end_b = 0;
	ps->min_a = ps->end_a->num;
	ps->max_a = ps->end_a->num;
}

int				put_to_stack(char *str, t_stack **stack)
{
	long long	num;
	t_stack		*tmp;
	int			str_pos;

	tmp = 0;
	str_pos = 0;
	num = ps_atoi(str, &str_pos);
	if (!(tmp = ft_create_elem(num)) || num > INT_MAX || num < INT_MIN)
		pr_error();
	ft_stack_push_back(stack, tmp);
	return (str_pos);
}

void			parse_multi_args(char *str, t_stack **stack)
{
	while (*str)
		str += put_to_stack(str, stack);
}

char			fill_stack(t_push_swap *ps, char **argv)
{
	ps->stack_a = 0;
	ps->option_print = 0;
	ps->option_color = 0;
	if ((!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-vc"))
												&& argv[0][2] == 'c')
	{
		ps->option_print = argv[1][1] == 'v' ? 1 : 0;
		ps->option_color = argv[1][2] == 'c' ? 1 : 0;
		argv++;
	}
	while (*(++argv))
	{
		if (ft_strchr(*argv, ' ') || ft_strchr(*argv, '\t'))
			parse_multi_args(*argv, &ps->stack_a);
		else if (is_num(*argv))
			put_to_stack(*argv, &ps->stack_a);
		else
			return (0);
	}
	return (1);
}
