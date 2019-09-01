/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:03:43 by lbellona          #+#    #+#             */
/*   Updated: 2019/06/28 14:21:03 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = -1;
	while (src[++i])
		ret[i] = src[i];
	ret[i] = '\0';
	return (ret);
}
