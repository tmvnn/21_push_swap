/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timuryakubov <timuryakubov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2019/08/01 20:14:17 by timuryakubo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_str_width(t_pf *pf, int len)
{
	while (pf->flag.fwidth-- > len)
		pf->buff[pf->ib++] = pf->flag.zero ? '0' : ' ';

}

void			print_char(t_pf *pf, char c)
{
	if (pf->flag.minus)
	{
		pf->buff[pf->ib++] = c;
		print_str_width(pf, 1);
	}
	else
	{
		print_str_width(pf, 1);
		pf->buff[pf->ib++] = c;
	}
}

void			put_str_2_buff(t_pf *pf, char *str, int len)
{
	while (len--)
		pf->buff[pf->ib++] = *str++;
}

void			print_str(t_pf *pf, char *str)
{
	int 		len;

	len = ft_strlen(str);
	(pf->prec >= 0 && pf->prec < len) ? len = pf->prec : 0;
	if (pf->flag.minus)
	{
		put_str_2_buff(pf, str, len);
		print_str_width(pf, len);
	}
	else
	{
		print_str_width(pf, len);
		put_str_2_buff(pf, str, len);
	}
}

void			s_char(t_pf *pf, char tp)
{
	int			chrcter;
	char		*str;

	pf->flag.minus == 1 ? pf->flag.zero = 0 : 0;
	if (tp == 'c')
	{
		chrcter = va_arg(pf->argptr, int);
		print_char(pf, chrcter);
	}
	else
	{
		str = va_arg(pf->argptr, char*);
		if (str == 0)
			print_str(pf, "(null)");
		else
			print_str(pf, str);
	}
	pf->i++;
}
