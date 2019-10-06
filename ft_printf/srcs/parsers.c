/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		parse_flag_mod_prec(const char *str, t_pf *pf)
{
	init_flags(pf);
	while (str[pf->i] && (is_flag(str[pf->i]) || is_precision(str[pf->i])
						|| is_modifier(str[pf->i])))
	{
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
