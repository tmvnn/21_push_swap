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

#ifndef CHECKER_H
# define CHECKER_H

//# define BUFF_SIZE1 3
# define ALLOWABLE_SYMB "0123456789"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/includes/libft.h"

typedef struct		s_stack
{
	int					num;
	struct s_stack		*next;

}					t_stack;

/*
** ---------------------------- Main Functions ------------------------------
*/

//int				ft_printf(const char * restrict format, ...);
void				*pr_error(void);
void				valid_and_sort(t_stack **stack_a);

/*
** ----------------------------- libft Functions -------------------------------
*/

char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
long long			ps_atoi(const char *str, int *s);
char				*ft_strchr(const char *s, int c);


#endif
