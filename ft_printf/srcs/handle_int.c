/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 22:53:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_int_prec(t_pf *pf)
{
	int			i;
	char		*tmp;
	char		*newstr;

	pf->prec >= 0 ? pf->flag.zero = 0 : 0;
	if (pf->out[0] == '0' && pf->prec == 0)
	{
		pf->out[0] = 0;
		pf->n_len = 0;
	}
	else if (pf->prec > pf->n_len)
	{
		i = pf->prec - pf->n_len;
		tmp = ft_strnew(i);
		ft_memset(tmp, '0', i);
		newstr = ft_strjoin(tmp, pf->out);
		free(tmp);
		free(pf->out);
		pf->out = newstr;
		pf->n_len += i;
		pf->flag.zero = 0;
	}
}

void			s_int(t_pf *pf)
{
	intmax_t	num;

	pf->flag.minus == 1 ? pf->flag.zero = 0 : 0;
	num = va_arg(pf->argptr, intmax_t);
	if (pf->mod == no_mod)
		pf->out = ft_iltoa((int)num);
	else if (pf->mod == h_mod)
		pf->out = ft_iltoa((short)num);
	else if (pf->mod == hh_mod)
		pf->out = ft_iltoa((char)num);
	else if (pf->mod == l_mod)
		pf->out = ft_iltoa((long)num);
	else if (pf->mod == ll_mod)
		pf->out = ft_iltoa((long long)num);
	else if (pf->mod == j_mod || pf->mod == t_mod)
		pf->out = ft_iltoa((intmax_t)num);
	else if (pf->mod == z_mod)
		pf->out = ft_iltoa((size_t)num);
	get_sign_info(pf);
	handle_int_prec(pf);
	print_inum(pf);
	free(pf->out);
	pf->i++;
}

void			get_sign_info(t_pf *pf)
{
	char		*tmp;

	if (pf->out[0] == '-')
	{
		pf->is_neg = 1;
		pf->flag.plus = 0;
		pf->flag.space = 0;
		tmp = ft_strdup(pf->out + 1);
		free(pf->out);
		pf->out = tmp;
	}
	pf->n_len = (int)ft_strlen(pf->out);
}
