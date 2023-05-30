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
	printf("hola\n");
	init_player(map);
	print_walls(args, map, map->player);
	// mlx_get_time;
	// mlx_loop(mlx);
}

void	init_player(t_map	*map)
{
	map->player = malloc(sizeof(t_player));
	printf("pj x = %d\n", map->pj->x);
	printf("orie = %c\n", map->pj->orientation);
	map->player->x = map->pj->x;
	map->player->y = map->pj->y;
	map->player->planex = 0;
	map->player->planey = 0.66;
	map->player->dirx = 0;
	map->player->diry = 0;

	if (map->pj->orientation == 'N')
		map->player->diry = 1;
	else if (map->pj->orientation == 'S')
		map->player->diry = -1;
	else if (map->pj->orientation == 'E')
		map->player->dirx = 1;
	else if (map->pj->orientation == 'W')
		map->player->dirx = -1;
	printf("dirx= %f\n", map->player->dirx);
}

void	hook(void *param)
{
	t_args	*args;

	args = (t_args *) param;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		rotate(args->map->player, 0.08);
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		rotate(args->map->player, -0.08);

	// moves:
	// keydata.key == MLX_KEY_D
	// keydata.key == MLX_KEY_A
}
void	rotate(t_player *pl, float a)
{
	const float	old_dirx = pl->dirx;
	const float	oldcamx = pl->raydirx;
	const float	v_cos = cosf(a);
	const float	v_sin = sinf(a);

	pl->dirx = old_dirx * v_cos - pl->diry * v_sin;
	pl->diry = old_dirx * v_sin + pl->diry * v_cos;
	pl->raydirx = oldcamx * v_cos - pl->raydiry * v_sin;
	pl->raydiry = oldcamx * v_sin + pl->raydiry * v_cos;
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

	args->walls = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	x = 0;
	while (x < WIDTH)
	{
		pl->camerax = 2 * x / (double)WIDTH - 1;
		// printf("x: %d, camara: %f\n", x, pl->camerax);
		pl->raydirx = pl->dirx + pl->planex * pl->camerax;
		pl->raydiry = pl->diry + pl->planey * pl->camerax;
		// printf("rayx: %f, rayy: %f\n", pl->raydirx, pl->raydiry);
		pl->mapx = (int)(pl->x);
		pl->mapy = (int)(pl->y);
		pl->hit = 0;
		printf("mapy = %d\n", pl->mapy);
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
				pl->sidedistx += pl->sidedistx;
				// printf("stepx = %d\n", pl->stepx);
				pl->mapx += pl->stepx;
				pl->side = 0;
			}
			else
			{
				// printf("stepy = %d\n", pl->stepy);
				pl->sidedisty += pl->sidedisty;
				// printf("x = %d y = %d\n", pl->mapx, pl->mapy);
				pl->mapy += pl->stepy;
				// printf("fuaaaax = %d y = %d\n", pl->mapx, pl->mapy);
				pl->side = 1;
			}
			//printf("x = %d y = %d, map: %c\n", pl->mapx, pl->mapy, map->map_fill[pl->mapy][pl->mapx]);
			if (map->map_fill[pl->mapy][pl->mapx] == '1')
				pl->hit = 1;
		}
		// printf("sdx: %f, sdy: %f, ddx: %f, ddy: %f\n", pl->sidedistx, pl->sidedisty, pl->deltadistx, pl->deltadisty);
		if (pl->side == 0)
			pl->perpwalldist = pl->sidedistx - pl->deltadistx;
		else
			pl->perpwalldist = pl->sidedisty - pl->deltadisty;
		pl->lineheight = (int)(HEIGHT / (pl->perpwalldist / 100));
		// printf("lineheight: %d, perpwalldist: %f\n", pl->lineheight, pl->perpwalldist);
		pl->drawstart = -pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawstart < 0)
			pl->drawstart = 0;
		pl->drawend = pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawend >= HEIGHT)
			pl->drawend = HEIGHT - 1;
// Diferenciar lado para pintar de un text o otra
		print_vert_line(x, pl->drawstart, pl->drawend, 0xFBAED2FF, args);
		x++;
	}
	mlx_image_to_window(args->mlx, args->walls, 0, 0);
}

void	print_vert_line(int x, int ystart, int yend, int color, t_args *args)
{
	
	// printf("raya x: %d, y0: %d, y1: %d\n", x, ystart, yend);
	while(ystart <= yend)
	{		
		mlx_put_pixel(args->walls, x, ystart, color);
		ystart++;
	}
}
