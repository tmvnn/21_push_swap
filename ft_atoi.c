/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:37:47 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/04 23:28:01 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static unsigned long long		get_num(const char *str, int *s, int sign)
{
	int 						s_len;
	unsigned long long			rez;

	rez = 0;
	s_len = 0;
	while (str[*s] >= 48 && str[*s] <= 57)
	{
		rez = rez * 10 + str[*s] - 48;
		*s = *s + 1;
		if (rez > LLONG_MAX || (rez < ULLONG_MAX && ++s_len >= 20))
			return (sign == 1 ? -1 : 0);
	}
	if (str[*s] != ' ' && str[*s] != '\0' && str[*s] != '\t')
		pr_error();
	while (str[*s] == 32 || (str[*s] >= 9 && str[*s] <= 13))
		*s = *s + 1;
	return (rez);
}

long long						ft_atoi(const char *str, int *s)
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
	}
	return ((long long)sign * (long long)get_num(str, s, sign));
}
