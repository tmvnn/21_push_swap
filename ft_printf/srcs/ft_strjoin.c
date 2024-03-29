/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:33:46 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	lens1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	if (!(nstr = ft_strnew(lens1 + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ft_strcpy(nstr, s1) + lens1, s2);
	return (nstr);
}
