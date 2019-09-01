/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/09 15:46:06 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_strmemal(uintmax_t num, size_t *size_n)
{
	*size_n = 1;
	if (num < 0)
		*size_n = *size_n + 1;
	while ((num = num / 10))
		*size_n = *size_n + 1;
	return (ft_strnew(*size_n));
}

char				*ft_ultoa(uintmax_t n)
{
	size_t			size_n;
	uintmax_t	num;
	char			*str;
	char			*ret;

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
		if (num > 9)
		{
			str[size_n] = '0' + num % 10;
			num /= 10;
		}
		else
			str[size_n] = '0' + num;
	}
	return (ret);
}
