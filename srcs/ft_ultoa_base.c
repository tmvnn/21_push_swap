/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/07/09 17:29:16 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_strmemal(uintmax_t num, size_t *size_n, int base)
{
	*size_n = 1;
	if (num < 0)
		*size_n = *size_n + 1;
	while ((num = num / base))
		*size_n = *size_n + 1;
	return (ft_strnew(*size_n));
}

char				*ft_ultoa_base(uintmax_t n, int base, char cap)
{
	size_t			size_n;
	uintmax_t		num;
	char			*str;
	char			*ret;

	if (!(str = ft_strmemal(n, &size_n, base)))
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
		str[size_n] = num % base < 10 ? num % base + '0' : num % base + cap - 10;
		num /= base;
	}
	return (ret);
}
