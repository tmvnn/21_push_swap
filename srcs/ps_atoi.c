/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:37:47 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/11 21:01:25 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static unsigned long long		get_num(const char *str, int *s,
															t_push_swap *ps)
{
	int							s_len;
	unsigned long long			rez;
	char						n_flag;

	rez = 0;
	s_len = 0;
	n_flag = 1;
	while (str[*s] >= 48 && str[*s] <= 57)
	{
		n_flag = 0;
		rez = rez * 10 + str[*s] - 48;
		*s = *s + 1;
		if (rez > LLONG_MAX || (rez < ULLONG_MAX && ++s_len >= 20))
			pr_error(ps);
	}
	if (str[*s] != ' ' && str[*s] != '\0' && str[*s] != '\t')
		pr_error(ps);
	n_flag == 1 ? pr_error(ps) : 0;
	while (str[*s] == 32 || (str[*s] >= 9 && str[*s] <= 13))
		*s = *s + 1;
	return (rez);
}

long long						ps_atoi(const char *str, int *s,
															t_push_swap *ps)
{
	int							sign;

	*s = 0;
	while (str[*s] == 32 || (str[*s] >= 9 && str[*s] <= 13))
		*s = *s + 1;
	sign = 1;
	if (str[*s] == 43 || str[*s] == 45)
	{
		if (str[*s] == 45)
			sign = -1;
		*s = *s + 1;
		if (str[*s] < 48 || str[*s] > 57)
			pr_error(ps);
	}
	return ((long long)sign * (long long)get_num(str, s, ps));
}
