/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/09 18:11:46 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_strmemal(intmax_t num, size_t *size_n)
{
	if (num == LONG_MIN)
	{
		*size_n = 0;
		return (ft_strdup("-9223372036854775808"));
	}
	*size_n = 1;
	if (num < 0)
		*size_n = *size_n + 1;
	while ((num = num / 10))
		*size_n = *size_n + 1;
	return (ft_strnew(*size_n));
}

char			*ft_iltoa(intmax_t n)
{
	size_t		size_n;
	intmax_t	num;
	char		*str;
	char		*ret;

	if (!(str = ft_strmemal(n, &size_n)))
		return (NULL);
	ret = str;
	if ((num = n) < 0 && size_n > 0)
	{
		*str++ = '-';
		num = -num;
		size_n--;
	}
	while (size_n--)
	{
		str[size_n] = '0' + num % 10;
		num /= 10;
	}
	return (ret);
}
