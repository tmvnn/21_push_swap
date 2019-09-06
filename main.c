/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/06 18:22:13 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int		main(int argc, char **argv)
{

	if (argc > 1)
		while (*(++argv))
		{
			write(1, *argv, 3);
			write(1, "\n", 1);
		}

	return (0);
}

