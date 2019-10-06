/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:52:29 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (void*)malloc(sizeof(void) * size)))
		return (0);
	while (size--)
		*(ret + size) = 0;
	return ((void *)ret);
}
