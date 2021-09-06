/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:34:00 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/01 15:16:29 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_message(int code)
{
	if (code == 1)
		ft_printf("Error! Unkown character on map!\n");
	else if (code == 0)
		ft_printf("Error! Missing components or extra player on map!\n");
	else if (code == 2)
		ft_printf("Error! Invalid map, try again!\n");
	exit (0);
}

void	minimun_check(t_player *p, int index_x, int index_y, int *checks)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < index_y)
	{
		while (x < index_x)
		{
			if (p->line[y][x] == 'E')
				checks[0] = 1;
			else if (p->line[y][x] == 'C')
				checks[1] = 1;
			else if (p->line[y][x] == 'P')
				checks[2]++;
			else if (p->line[y][x] != '1' && p->line[y][x] != '0')
				checks[3] = 1;
			x++;
		}
		x = 0;
		y++;
	}
	if (checks[0] != 1 || checks[1] != 1 || checks[2] != 1 || checks[3] == 1)
		error_message(checks[3]);
}

void	wall_result(t_player *p, int index_x, int index_y, int okay)
{
	int	checks[4];

	checks[0] = 0;
	checks[1] = 0;
	checks[2] = 0;
	checks[3] = 0;
	if (okay == 1)
		minimun_check(p, index_x, index_y, checks);
	else
	{
		ft_printf("Error! The map needs to be surrounded by walls!\n");
		exit (0);
	}
}

void	wall_checker(t_player *p, int index_x, int index_y)
{
	int	i;
	int	okay;

	i = 0;
	okay = 1;
	while (i < index_x)
	{
		if (p->line[0][i] != '1')
			okay = 0;
		if (p->line[index_y - 1][i] != '1')
			okay = 0;
		i++;
	}
	i = 0;
	while (i < index_y)
	{
		if (p->line[i][0] != '1')
			okay = 0;
		if (p->line[i][index_x - 1] != '1')
			okay = 0;
		i++;
	}
	wall_result(p, index_x, index_y, okay);
}

void	make_screen(t_player *p, char *argv)
{
	int	fd;
	int	index_y;
	int	index_x;

	index_y = 0;
	index_x = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0 || fd > 10000)
		error_message(2);
	while (get_next_line(fd, &p->line[index_y]) == 1)
		index_y++;
	while (p->line[index_y - 1][index_x])
		index_x++;
	wall_checker(p, index_x, index_y);
	p->v.m = mlx_init();
	p->v.w = mlx_new_window(p->v.m, (index_x) * 64, index_y * 64, "so_long");
	assign_sprites(p);
	put_sprites(p, index_x, index_y);
	ft_printf("Movements: %d\n", p->mo);
	ft_printf("Sugar cubes left: %d\n", p->objs);
}
