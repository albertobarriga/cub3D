#include "../../includes/cub3D.h"

void	print_back(t_args *args, t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mid_height;

	(void)map;
	args->back = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	if (!args->back)
	{
		free_structs(args);
		free_cube(args);
	}
	mid_height = HEIGHT / 2;
	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			if (j < mid_height)
				mlx_put_pixel(args->back, i, j, map->floor_color);
			else
				mlx_put_pixel(args->back, i, j, map->ceiling_color);
		}
	}
	mlx_image_to_window(args->mlx, args->back, 0, 0);
}

uint8_t	*take_pixel(t_player *pl, t_args *args)
{
	uint8_t	*pixel;

	if (pl->side == 0)
		pixel = &args->we_text->pixels[pl->tex_width * pl->tex_y * 4
			+ pl->tex_x * 4];
	else if (pl->side == 1)
		pixel = &args->no_text->pixels[pl->tex_width * pl->tex_y * 4
			+ pl->tex_x * 4];
	else if (pl->side == 2)
		pixel = &args->ea_text->pixels[pl->tex_width * pl->tex_y * 4
			+ pl->tex_x * 4];
	else
		pixel = &args->so_text->pixels[pl->tex_width * pl->tex_y * 4
			+ pl->tex_x * 4];
	return (pixel);
}

void	info_hit(t_player *pl)
{
	int	dirx;
	int	diry;

	dirx = pl->mapx - pl->x;
	diry = pl->mapy - pl->y;
	if (pl->side == 0)
	{
		if (dirx >= 0)
			pl->side += 2;
	}
	if (pl->side == 1)
	{
		if (diry >= 0)
			pl->side += 2;
	}
}
