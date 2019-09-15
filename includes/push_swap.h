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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

typedef struct		s_params
{
	int					d_head;
	int					pos_a;
	struct s_params		*next;
	struct s_params		*prev;

}					t_params;

typedef struct		s_push_swap
{
	int				size;
	//int				size_a;
	int				size_b;
	t_stack			*stack_a;
	t_stack			*end_a;
	t_stack			*stack_b;
	t_stack			*end_b;
	//struct s_stack		*next;

}					t_push_swap;



/*
** ---------------------------- Main Functions ------------------------------
*/

/*
** --------------------------- Operations Functions ----------------------------
*/


/*
** ----------------------------- libft Functions -------------------------------
*/


#endif
