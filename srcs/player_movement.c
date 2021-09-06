/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:34:13 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/01 14:44:44 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	position_change(t_player *p, int move_x, int move_y)
{
	p->m.x += move_y;
	p->m.y += move_x;
	ft_printf("Movements: %d\n", ++p->mo);
}

void	walking_to_wall(int keycode, t_player *p)
{
	if (keycode == 1)
	{
		if (p->line[p->m.y + 1][p->m.x] != '1')
			position_change(p, 1, 0);
	}
	else if (keycode == 13)
	{
		if (p->line[p->m.y - 1][p->m.x] != '1')
			position_change(p, -1, 0);
	}
	else if (keycode == 0)
	{
		if (p->line[p->m.y][p->m.x - 1] != '1')
			position_change(p, 0, -1);
	}
	else if (keycode == 2)
	{
		if (p->line[p->m.y][p->m.x + 1] != '1')
			position_change(p, 0, 1);
	}
	else if (keycode == 53)
		exit (0);
}

void	objective_check(t_player *p)
{
	if (p->line[p->m.y][p->m.x] == 'C')
	{
		p->objs--;
		if (p->objs > 0)
			ft_printf("Sugar cubes left: %d\n", p->objs);
		else
			ft_printf("All sugar cubes collected! Go mate!\n");
		p->line[p->m.y][p->m.x] = '0';
	}
	else if (p->line[p->m.y][p->m.x] == 'E')
	{
		if (p->objs > 0)
			ft_printf("You still don't have all the sugar cubes!\n");
		else
		{
			ft_printf("Winner, winner, chicken dinner! Closing program!\n");
			exit(0);
		}
	}
}

int	player_movement(int keycode, t_player *p)
{
	int	i;

	i = 64;
	mlx_put_image_to_window(p->v.m, p->v.w, p->f.i, p->m.x * i, p->m.y * i);
	if (p->line[p->m.y][p->m.x] == 'E')
		mlx_put_image_to_window(p->v.m, p->v.w, p->q.i, p->m.x * i, p->m.y * i);
	walking_to_wall(keycode, p);
	mlx_put_image_to_window(p->v.m, p->v.w, p->m.i, p->m.x * i, p->m.y * i);
	objective_check(p);
	return (0);
}
