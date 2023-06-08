#include "../../includes/cub3D.h"

void	mlx_load_text(t_args *args, t_map *map)
{
	args->no_text = mlx_load_png(map->no);
	args->so_text = mlx_load_png(map->so);
	args->we_text = mlx_load_png(map->we);
	args->ea_text = mlx_load_png(map->ea);
	if (!args->no_text || !args->so_text || !args->we_text || !args->ea_text)
		exit_cub(args);
}

void	print_walls(t_args *args, t_map *map, t_player *pl)
{
	int	x;

	if (args->walls)
		mlx_delete_image(args->mlx, args->walls);
	args->walls = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	x = 0;
	while (x < WIDTH)
	{
		get_positions(pl, x);
		get_step_sidedist(pl);
		check_hit(pl, map);
		get_linetoprint(pl);
		info_hit(pl);
		info_tex(pl, args);
		printline_text(pl, args, x);
		x++;
	}
	mlx_image_to_window(args->mlx, args->walls, 0, 0);
}

void	info_tex(t_player *pl, t_args *args)
{
	double	wallx;

	take_measures(pl, args);
	if (pl->side == 0 || pl->side == 2)
		wallx = pl->y + pl->perpwalldist * pl->raydiry;
	else
		wallx = pl->x + pl->perpwalldist * pl->raydirx;
	wallx = wallx - (int)wallx;
	pl->tex_x = (int)(wallx * (double)pl->tex_width);
	if ((pl->side == 2 || pl->side == 1))
		pl->tex_x = pl->tex_width - pl->tex_x - 1;
}

void	take_measures(t_player *pl, t_args *args)
{
	if (pl->side == 0)
	{
		pl->tex_width = args->we_text->width;
		pl->tex_height = args->we_text->height;
	}
	else if (pl->side == 1)
	{
		pl->tex_width = args->no_text->width;
		pl->tex_height = args->no_text->height;
	}
	else if (pl->side == 2)
	{
		pl->tex_width = args->ea_text->width;
		pl->tex_height = args->ea_text->height;
	}
	else if (pl->side == 3)
	{
		pl->tex_width = args->so_text->width;
		pl->tex_height = args->so_text->height;
	}
}

void	printline_text(t_player *pl, t_args *args, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	uint8_t	*p;

	step = (double)pl->tex_height / pl->lineheight;
	tex_pos = (pl->drawstart - HEIGHT / 2 + pl->lineheight / 2) * step;
	y = pl->drawstart;
	while (y < pl->drawend)
	{
		pl->tex_y = (int)tex_pos;
		if (pl->tex_y > pl->tex_height)
			pl->tex_y = pl->tex_height;
		tex_pos += step;
		p = take_pixel(pl, args);
		pl->color = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
		mlx_put_pixel(args->walls, x, y, pl->color);
		y++;
	}
}
