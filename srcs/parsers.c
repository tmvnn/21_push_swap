/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/08/06 12:48:00 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	//else if (str[pf->i] == 's' || str[pf->i] == 'c' ||
				//str[pf->i] == 'S' || str[pf->i] == 'C')
	else if (str[pf->i] == 's' || str[pf->i] == 'c')
		s_char(pf, str[pf->i]);
	else if (str[pf->i] == 'p')
	{
		pf->mod = l_mod;
		pf->flag.hash = 1;
		s_uint_base(pf, str[pf->i]);
	}
}

void		init_flags(t_pf *pf)
{
	pf->is_neg = 0;
	pf->n_len = 0;
	pf->prec = -1;
	pf->flag.hash = 0;
	pf->flag.zero = 0;
	pf->flag.minus = 0;
	pf->flag.plus = 0;
	pf->flag.space = 0;
	pf->flag.fwidth = 0;
	pf->mod = no_mod;
	pf->tp = 0;
}

void		parse_mod(const char *str, t_pf *pf)
{
	if (str[pf->i] == 'h' && str[pf->i + 1] != 'h' && pf->mod == no_mod)
		pf->mod = h_mod;
	else if (str[pf->i] == 'h' && str[pf->i + 1] == 'h' && pf->mod == no_mod)
	{
		pf->i++;
		pf->mod = hh_mod;
	}
	else if (str[pf->i] == 'l' && str[pf->i + 1] != 'l')
		pf->mod = l_mod;
	else if (str[pf->i] == 'l' && str[pf->i + 1] == 'l')
	{
		pf->i++;
		pf->mod = ll_mod;
	}
	else if (str[pf->i] == 'L')
		pf->mod = L_mod;
	else if (str[pf->i] == 'j')
		pf->mod = j_mod;
	else if (str[pf->i] == 'z')
		pf->mod = z_mod;
	else if (str[pf->i] == 't')
		pf->mod = t_mod;
}

void		parse_prec(const char *str, t_pf *pf)
{
	pf->i++;
	if (pf->prec >= 0)
	{
		pf->i++;
		return ;
	}
	pf->prec = ft_atoi(str + pf->i);
	while (str[pf->i] >= '0' && str[pf->i] <= '9')
		pf->i++;
}

void    	parse_flag_mod_prec(const char *str, t_pf *pf)
{
	init_flags(pf);
	while (str[pf->i] && (is_flag(str[pf->i]) || is_precision(str[pf->i])
						|| is_modifier(str[pf->i])))
	//while (str[pf->i] && ft_strchr(PF_FLAG, str[pf->i]))
	{
		//Можно ускорить переписав через else if
		str[pf->i] == '#' ? pf->flag.hash = 1 : 0;
		str[pf->i] == '0' ? pf->flag.zero = 1 : 0;
		str[pf->i] == '-' ? pf->flag.minus = 1 : 0;
		str[pf->i] == '+' ? pf->flag.plus = 1 : 0;
		str[pf->i] == ' ' ? pf->flag.space = 1 : 0;
		str[pf->i] == '#' ? pf->flag.hash = 1 : 0;
		parse_mod(str, pf);
		if (str[pf->i] == '.')
			parse_prec(str, pf);
		else if (str[pf->i] >= '1' && str[pf->i] <= '9' && pf->prec < 0)
		{
			pf->flag.fwidth = ft_atoi(str + pf->i);
			while (str[pf->i] >= '0' && str[pf->i] <= '9')
				pf->i++;
		}
		else
			pf->i++;
	}
}
