/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			s_uint(t_pf *pf, char tp)
{
	intmax_t	num;

	pf->flag.plus = 0;
	pf->flag.space = 0;
	num = va_arg(pf->argptr, intmax_t);
	if (tp != 'U' && pf->mod == no_mod)
		pf->out = ft_ultoa((unsigned int)num);
	else if (tp == 'U' || pf->mod == l_mod)
		pf->out = ft_ultoa((unsigned long)num);
	else if (pf->mod == h_mod)
		pf->out = ft_ultoa((unsigned short)num);
	else if (pf->mod == hh_mod)
		pf->out = ft_ultoa((unsigned char)num);
	else if (pf->mod == ll_mod)
		pf->out = ft_ultoa((unsigned long long)num);
	else if (pf->mod == j_mod || pf->mod == t_mod)
		pf->out = ft_ultoa((uintmax_t)num);
	else if (pf->mod == z_mod)
		pf->out = ft_ultoa((size_t)num);
	get_sign_info(pf);
	handle_int_prec(pf);
	print_inum(pf);
	free(pf->out);
	pf->i++;
}

void			handle_hash(t_pf *pf, char tp)
{
	char		*tmp;

	if (pf->flag.hash && !pf->flag.zero)
	{
		if ((pf->out[0] == 0 && pf->n_len == 0 && tp != 'o' && tp != 'O' &&
			tp != 'p') || (pf->out[0] == '0' && pf->n_len == 1 && tp != 'p'))
			return ;
		tmp = pf->out;
		if (tp == 'X')
		{
			pf->out = ft_strjoin("0X", pf->out);
			pf->n_len += 2;
		}
		else if (tp == 'x' || tp == 'p')
		{
			pf->out = ft_strjoin("0x", pf->out);
			pf->n_len += 2;
		}
		else
		{
			pf->out = ft_strjoin("0", pf->out);
			pf->n_len++;
		}
		free(tmp);
	}
}

static void		check_mod(t_pf *pf, char tp, intmax_t *num)
{
	if (pf->mod == no_mod)
		*num = (unsigned int)*num;
	else if (tp == 'O' || pf->mod == l_mod)
		*num = (unsigned long)*num;
	else if (pf->mod == h_mod)
		*num = (unsigned short)*num;
	else if (pf->mod == hh_mod)
		*num = (unsigned char)*num;
	else if (pf->mod == ll_mod)
		*num = (unsigned long long)*num;
	else if (pf->mod == j_mod || pf->mod == t_mod)
		*num = (uintmax_t)*num;
	else if (pf->mod == z_mod)
		*num = (size_t)*num;
}

void			s_uint_base(t_pf *pf, char tp)
{
	intmax_t	num;

	pf->flag.plus = 0;
	pf->flag.space = 0;
	pf->flag.minus == 1 ? pf->flag.zero = 0 : 0;
	pf->tp = tp;
	(pf->tp == 'o' || pf->tp == 'O') && pf->flag.hash ? pf->prec-- : 0;
	num = va_arg(pf->argptr, intmax_t);
	check_mod(pf, tp, &num);
	(tp == 'o' || tp == 'O') ? pf->out = ft_ultoa_base(num, 8, tp - 14) : 0;
	(tp == 'x' || tp == 'X') ? pf->out = ft_ultoa_base(num, 16, tp - 23) : 0;
	(tp == 'p') ? pf->out = ft_ultoa_base(num, 16, 'a') : 0;
	get_sign_info(pf);
	handle_int_prec(pf);
	handle_hash(pf, tp);
	print_inum(pf);
	free(pf->out);
	pf->i++;
}
