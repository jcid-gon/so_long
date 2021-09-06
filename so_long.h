/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:32:14 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/01 12:41:33 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars{
	void	*m;
	void	*w;
}			t_vars;

typedef struct s_sprite{
	void	*i;
	char	*rp;
	int		d[2];
	int		x;
	int		y;
}			t_sprite;

typedef struct s_player{
	t_vars		v;
	t_sprite	m;
	t_sprite	f;
	t_sprite	q;
	t_sprite	sw;
	t_sprite	sc;
	char		*line[1000000];
	int			objs;
	int			mo;
}			t_player;

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	assign_sprites(t_player *p);
void	add_collectible(t_player *p, int x, int y);
void	spawn_player(t_player *p, int x, int y);
void	put_sprites(t_player *p, int index_x, int index_y);
void	error_message(int code);
void	minimun_check(t_player *p, int index_x, int index_y, int *checks);
void	wall_result(t_player *p, int index_x, int index_y, int okay);
void	wall_checker(t_player *p, int index_x, int index_y);
void	make_screen(t_player *p, char *argv);
void	objective_check(t_player *p);
void	position_change(t_player *p, int move_x, int move_y);
void	walking_to_wall(int keycode, t_player *p);
int		player_movement(int keycode, t_player *p);
int		close_window(void);

#endif
