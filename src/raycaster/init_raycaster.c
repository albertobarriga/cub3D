#include "../../includes/cub3D.h"

void	init_args_mlx(t_args *args)
{
	args->no_text = NULL;
	args->so_text = NULL;
	args->we_text = NULL;
	args->ea_text = NULL;
	args->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!args->mlx)
		free(args);
		// error y frees
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	if (!args->img)
		free(args);
		// error y frees
}

void	init_args(t_args *args, t_map *map)
{
	mlx_load_text(args, map);
	mlx_loop_hook(args->mlx, &hook, args);
	// mlx_set_cursor_mode(args->mlx, MLX_MOUSE_DISABLED);
	print_back(args, map);
	init_player(map);
	print_walls(args, map, map->player);
	// mlx_get_time;
	// mlx_loop(args->mlx);
}

void	init_player(t_map	*map)
{
	map->player = malloc(sizeof(t_player));
	printf("pj x = %d\n", map->pj->x);
	printf("orie = %c\n", map->pj->orientation);
	map->player->x = map->pj->x;
	map->player->y = map->pj->y;
	map->player->dirx = 0;
	map->player->diry = 0;
	if (map->pj->orientation == 'N')
		map->player->diry = -1;
	else if (map->pj->orientation == 'S')
		map->player->diry = 1;
	else if (map->pj->orientation == 'E')
		map->player->dirx = 1;
	else if (map->pj->orientation == 'W')
		map->player->dirx = -1;
	if (map->player->dirx == 0)
	{
		map->player->planey = 0;
		map->player->planex = 0.66;
	}
	else
	{
		map->player->planex = 0;
		map->player->planey = 0.66;
	}
	printf("dirx= %f\n", map->player->dirx);
}

void	hook(void *param)
{
	t_args	*args;

	args = (t_args *) param;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		rotate(args->map->player, ROTATION);
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		rotate(args->map->player, -ROTATION);
	if (mlx_is_key_down(args->mlx, MLX_KEY_W))
		move(args, args->map->player->dirx, args->map->player->diry);
	if (mlx_is_key_down(args->mlx, MLX_KEY_S))
		move(args, -args->map->player->dirx, -args->map->player->diry);
	if (mlx_is_key_down(args->mlx, MLX_KEY_D))
		move(args, args->map->player->planex, args->map->player->planey);
	if (mlx_is_key_down(args->mlx, MLX_KEY_A))
		move(args, -args->map->player->planex, -args->map->player->planey);
	print_walls(args, args->map, args->map->player);
}

void	move(t_args *args, double varx, double vary)
{
	double	new_x;
	double	new_y;

	new_x = args->map->player->x + varx * 0.2;
	new_y = args->map->player->y + vary * 0.2;
	// printf("mapx = %d, mapy= %d\n", pl->mapx, pl->mapy);
	// printf("posicion del mapa = %c\n", args->map->map_fill[(int)roundl(new_y + args->map->player->diry / 1e5)][(int)roundl(new_x + 0.49 + args->map->player->dirx / 1e5)]);
	if (args->map->map_fill[(int)args->map->player->y][(int)(new_x + args->map->player->dirx / 1e5)] != '1')
		args->map->player->x = new_x;
	if (args->map->map_fill[(int)(new_y + args->map->player->diry / 1e5)][(int)args->map->player->x] != '1')
		args->map->player->y = new_y;
}

void	rotate(t_player *pl, double a)
{
	double	oldplanex;
	double	old_dirx;
	double	v_cos;
	double	v_sin;

	old_dirx = pl->dirx;
	oldplanex = pl->planex;
	v_cos = cosf(a);
	v_sin = sinf(a);
	pl->dirx = old_dirx * v_cos - pl->diry * v_sin;
	pl->diry = old_dirx * v_sin + pl->diry * v_cos;
	pl->planex = oldplanex * v_cos - pl->planey * v_sin;
	pl->planey = oldplanex * v_sin + pl->planey * v_cos;
}

void	print_back(t_args *args, t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mid_height;

	(void)map;
	args->back = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	if (!args->back)
		/*ERROR*/;
	mid_height = HEIGHT / 2;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (j < mid_height)
				mlx_put_pixel(args->back, i, j, map->floor_color);
			else
				mlx_put_pixel(args->back, i, j, map->ceiling_color);
			i++;
		}
		j++;
	}
	mlx_image_to_window(args->mlx, args->back, 0, 0);
}

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
		pl->camerax = 2 * x / (double)WIDTH - 1;
		// printf("x: %d, camara: %f\n", x, pl->camerax);
		pl->raydirx = pl->dirx + pl->planex * pl->camerax;
		pl->raydiry = pl->diry + pl->planey * pl->camerax;
		//printf("rayx: %f, rayy: %f\n", pl->raydirx, pl->raydiry);
		pl->mapx = (int)(pl->x);
		pl->mapy = (int)(pl->y);
		pl->hit = 0;
		// printf("mapy = %d\n", pl->mapy);
		if (pl->raydirx == 0)
			pl->deltadistx = 1e30;
		else
			pl->deltadistx = fabs(1 / pl->raydirx);
		if (pl->raydiry == 0)
			pl->deltadisty = 1e30;
		else
			pl->deltadisty = fabs(1 / pl->raydiry);
		if (pl->raydirx < 0)
		{
			pl->stepx = -1;
			pl->sidedistx = (pl->x - pl->mapx) * pl->deltadistx;
		}
		else
		{
			pl->stepx = 1;
			pl->sidedistx = (pl->mapx + 1.0 - pl->x) * pl->deltadistx;
		}
		if (pl->raydiry < 0)
		{
			pl->stepy = -1;
			pl->sidedisty = (pl->y - pl->mapy) * pl->deltadisty;
		}
		else
		{
			pl->stepy = 1;
			pl->sidedisty = (pl->mapy + 1.0 - pl->y) * pl->deltadisty;
		}
		while (pl->hit == 0)
		{
			if (pl->sidedistx < pl->sidedisty)
			{
				pl->sidedistx += pl->deltadistx;
				pl->mapx += pl->stepx;
				pl->side = 0;
			}
			else
			{
				pl->sidedisty += pl->deltadisty;
				pl->mapy += pl->stepy;
				pl->side = 1;
			}
			if (map->map_fill[pl->mapy][pl->mapx] == '1') {
			// printf("x = %d y = %d, rayx: %f, rayy: %f\n", pl->mapx, pl->mapy, pl->raydirx, pl->raydiry);
				pl->hit = 1;
			}
		}
		if (pl->side == 0)
			pl->perpwalldist = pl->sidedistx - pl->deltadistx;
		else
			pl->perpwalldist = pl->sidedisty - pl->deltadisty;
		pl->lineheight = (int)(HEIGHT / (pl->perpwalldist));
		pl->drawstart = -pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawstart < 0)
			pl->drawstart = 0;
		pl->drawend = pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawend >= HEIGHT)
			pl->drawend = HEIGHT - 1;

// Diferenciar lado para pintar de un text o otra
		info_hit(pl);
		info_tex(pl, args);
		printline_text(pl, args, x);
		// int color = pl->side ? 0xFBAED2FF : 0xfc030bff;
		// print_vert_line(x, pl->drawstart, pl->drawend, color, args);
		x++;
	}
	// mlx_delete_image(args->mlx, args->walls);
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
	// if ((pl->side == 1 || pl->side == 3) && pl->raydiry < 0)
	// 	pl->tex_x = pl->tex_width - pl->tex_x - 1;
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
	uint8_t *p;

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

// Esta funcion determina si es NSWE, si tenemos un side = 0, dependiendiendo del signo de la dirx + W - E y con side = 1 , dirx - N y dirx + S
void	info_hit(t_player *pl)
{
	int dirx;
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
	// printf("side = %d\n", pl->side);
}

// void	print_vert_line(int x, int ystart, int yend, int color, t_args *args)
// {
// 	// printf("raya x: %d, y0: %d, y1: %d\n", x, ystart, yend);
// 	while (ystart <= yend)
// 	{		
// 		mlx_put_pixel(args->walls, x, ystart, color);
// 		ystart++;
// 	}
// }
