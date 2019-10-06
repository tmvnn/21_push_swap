/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 23:14:48 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		s_percent(t_pf *pf)
{
	if (pf->flag.minus)
	{
		pf->buff[pf->ib++] = '%';
		while (pf->flag.fwidth-- > 1)
			pf->buff[pf->ib++] = ' ';
	}
	else
	{
		while (pf->flag.fwidth-- > 1)
			pf->buff[pf->ib++] = pf->flag.zero ? '0' : ' ';
		pf->buff[pf->ib++] = '%';
	}
	pf->i++;
}

void		parse_spec(const char *str, t_pf *pf)
{
	if (str[pf->i] == '%')
		s_percent(pf);
	else if (str[pf->i] == 'd' || str[pf->i] == 'i' || str[pf->i] == 'D')
		s_int(pf);
	else if (str[pf->i] == 'u' || str[pf->i] == 'U')
		s_uint(pf, str[pf->i]);
	else if (str[pf->i] == 'o' || str[pf->i] == 'O'
					|| str[pf->i] == 'x' || str[pf->i] == 'X')
		s_uint_base(pf, str[pf->i]);
	else if (str[pf->i] == 's' || str[pf->i] == 'c')
		s_char(pf, str[pf->i]);
	else if (str[pf->i] == 'p')
	{
		pf->mod = l_mod;
		pf->flag.hash = 1;
		s_uint_base(pf, str[pf->i]);
	}
}
