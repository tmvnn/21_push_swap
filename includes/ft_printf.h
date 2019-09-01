/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:22:41 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/17 23:28:26 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 4096
# define PF_FLAG " #*+-.0123456789Lhjltz"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct		s_pf_flags
{
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				fwidth;
}				t_pf_flags;

typedef enum		e_pf_mod
{
	no_mod = 0,
	h_mod,
	hh_mod,
	l_mod,
	ll_mod,
	L_mod,
	j_mod,
	z_mod,
	t_mod
}					t_pf_mod;

typedef struct		s_pf
{
	int				i;
	int				num_of_c;
	va_list			argptr;
	char			*out;
	int				n_len;
	t_pf_flags		flag;
	int				prec;
	int				is_neg;
	t_pf_mod		mod;
	int				ib;
	char			tp;
	char			buff[BUFF_SIZE + 1];
}					t_pf;

/*
** ---------------------------- Main Functions ------------------------------
*/

int				ft_printf(const char * restrict format, ...);
int				is_conversion(const char c);
int				is_flag(const char c);
int				is_precision(const char c);
int				is_modifier(const char c);
int				is_valid(const char c);
void			init_flags(t_pf *pf);
void			parse_str(const char *str, t_pf *pf);
void			parse_flag_mod_prec(const char *str, t_pf *pf);
void			parse_mod(const char *str, t_pf *pf);
void			parse_prec(const char *str, t_pf *pf);
void			parse_spec(const char *str, t_pf *pf);
void			s_percent(t_pf *pf);
void			s_int(t_pf *pf);
char			*ft_iltoa(intmax_t n);
void 			get_sign_info(t_pf *pf);
void			handle_int_prec(t_pf *pf);
void			put_num_2_buff(t_pf *pf);
void			print_inum(t_pf *pf);
void			print_width(t_pf *pf);
void			print_sign(t_pf *pf);
void			print_hash(t_pf *pf);
void			s_uint(t_pf *pf, char tp);
void			s_uint_base(t_pf *pf, char tp);
void			handle_hash(t_pf *pf, char tp);
char			*ft_ultoa(uintmax_t n);
char			*ft_ultoa_base(uintmax_t n, int base, char cap);
void			s_char(t_pf *pf, char tp);
void			print_str(t_pf *pf, char *str);
void			print_char(t_pf *pf, char c);
void			print_str_width(t_pf *pf, int len);
void			put_str_2_buff(t_pf *pf, char *str, int len);

/*
** ----------------------------- libft Functions -------------------------------
*/

char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
void			*ft_memset(void *b, int c, size_t len);

#endif
