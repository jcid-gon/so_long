/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:33:54 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/08/31 15:35:20 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	add_collectible(t_player *p, int x, int y)
{
	p->objs++;
	mlx_put_image_to_window(p->v.m, p->v.w, p->sc.i, x * 64 + 16, y * 64 + 16);
}

void	spawn_player(t_player *p, int x, int y)
{
	int	i;

	i = 64;
	p->m.x = x;
	p->m.y = y;
	mlx_put_image_to_window(p->v.m, p->v.w, p->m.i, p->m.x * i, p->m.y * i);
}

void	put_sprites(t_player *p, int index_x, int index_y)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 64;
	while (y < index_y)
	{
		while (x < index_x)
		{
			mlx_put_image_to_window(p->v.m, p->v.w, p->f.i, x * i, y * i);
			if (p->line[y][x] == '1')
				mlx_put_image_to_window(p->v.m, p->v.w, p->sw.i, x * i, y * i);
			if (p->line[y][x] == 'C')
				add_collectible(p, x, y);
			if (p->line[y][x] == 'E')
				mlx_put_image_to_window(p->v.m, p->v.w, p->q.i, x * i, y * i);
			if (p->line[y][x] == 'P')
				spawn_player(p, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	assign_sprites(t_player *p)
{
	p->m.rp = "./sprites/Mosca64.xpm";
	p->m.i = mlx_xpm_file_to_image(p->v.m, p->m.rp, &p->m.d[0], &p->m.d[1]);
	p->f.rp = "./sprites/Floor64.xpm";
	p->f.i = mlx_xpm_file_to_image(p->v.m, p->f.rp, &p->f.d[0], &p->f.d[1]);
	p->q.rp = "./sprites/Mosquita64.xpm";
	p->q.i = mlx_xpm_file_to_image(p->v.m, p->q.rp, &p->q.d[0], &p->q.d[1]);
	p->sw.rp = "./sprites/SpiderWeb64.xpm";
	p->sw.i = mlx_xpm_file_to_image(p->v.m, p->sw.rp, &p->sw.d[0], &p->sw.d[1]);
	p->sc.rp = "./sprites/sugarcube.xpm";
	p->sc.i = mlx_xpm_file_to_image(p->v.m, p->sc.rp, &p->sc.d[0], &p->sc.d[1]);
}
