/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/08/06 12:49:02 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		parse_str(const char *str, t_pf *pf)
{
	pf->i++;
	if (str[pf->i] && is_valid(str[pf->i]))
	{
		parse_flag_mod_prec(str, pf);
		parse_spec(str, pf);
	}
}

void		init_params(t_pf *pf)
{
	pf->i = 0;
	pf->num_of_c = 0;
	pf->ib = 0;
	pf->buff[pf->ib] = 0;
}

int			ft_printf(const char * restrict str, ...)
{
	t_pf	pf;

	va_start(pf.argptr, str);
	init_params(&pf);
	while (str[pf.i])
	{
		if (str[pf.i] == '%')
			parse_str(str, &pf);
		else
			pf.buff[pf.ib++] = str[pf.i++];
	}
	pf.ib = write(1, pf.buff, pf.ib);
	va_end(pf.argptr);
	return (pf.ib);
}
