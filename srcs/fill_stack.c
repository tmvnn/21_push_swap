/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:17:45 by timuryakubo       #+#    #+#             */
/*   Updated: 2019/09/12 18:19:01 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char			fill_stack(t_stack **stack, char **argv)
{
	*stack = 0;
	while (*(++argv))
	{
		if (ft_strchr(*argv, ' ') || ft_strchr(*argv, '\t'))/* Add tab etc. */
			parse_multi_args(*argv, stack);
		else if (is_num(*argv))
			put_to_stack(*argv, stack);
		else
			return (0);
	}
	return (1);
}
