/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/08 19:46:37 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{

	/*if (argc > 1)
		while (*(++argv))
		{
			write(1, *argv, 3);
			write(1, "\n", 1);
		}
		*/
	write(1, "sa\n", 3);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	write(1, "ra\n", 3);
	write(1, "rb\n", 3);
	write(1, "rra\n", 4);
	write(1, "rrb\n", 4);
	write(1, "sa\n", 3);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
	return (0);
}

