/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:31:46 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/01 15:16:09 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_player	p;

	if (argc != 2)
	{
		ft_printf("Invalid number of arguments, try again!\n");
		return (0);
	}
	p.objs = 0;
	p.mo = 0;
	make_screen(&p, argv[1]);
	mlx_hook(p.v.w, 2, 1L << 0, player_movement, &p);
	mlx_hook(p.v.w, 17, 1L << 17, close_window, &p);
	mlx_loop(p.v.m);
}
