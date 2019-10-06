/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:14:31 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(const char c)
{
	return (ft_strchr("dDioOuUxXcCsSp%", c) != 0);
}

int		is_flag(const char c)
{
	return (ft_strchr("#0-+ 123456789", c) != 0);
}

int		is_modifier(const char c)
{
	return (ft_strchr("hlLjzt", c) != 0);
}

int		is_precision(const char c)
{
	return (ft_strchr(".", c) != 0);
}

int		is_valid(const char c)
{
	return (is_conversion(c) || is_flag(c) || is_precision(c) ||
														is_modifier(c));
}
