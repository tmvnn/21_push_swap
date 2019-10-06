/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:00:04 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_strmemal(uintmax_t num, size_t *size_n, int base)
{
	*size_n = 1;
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
	num = n;
	while (size_n--)
	{
		str[size_n] = num % base < 10 ? num % base + '0' :
										num % base + cap - 10;
		num /= base;
	}
	return (ret);
}
