/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:52:29 by lbellona          #+#    #+#             */
/*   Updated: 2019/06/28 14:21:03 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (void*)malloc(sizeof(void) * size)))
		return (0);
	while (size--)
		*(ret + size) = 0;
	return ((void *)ret);
}
