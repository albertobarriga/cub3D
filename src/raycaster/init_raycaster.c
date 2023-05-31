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
	int	i;

	i = 0;
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
	map->player->x = map->pj->x + 0.5;
	map->player->y = map->pj->y + 0.5;
	map->player->planex = 0;
	map->player->planey = 0.66;
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
	printf("dirx= %f\n", map->player->dirx);
}

void	hook(void *param)
{
	t_args	*args;

	args = (t_args *) param;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
	{
		rotate(args->map->player, 0.0174533);
		print_walls(args, args->map, args->map->player);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
	{
		rotate(args->map->player, -0.0174533);
		print_walls(args, args->map, args->map->player);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_W))
	{
		args->map->player->x += args->map->player->dirx * 0.2;
		args->map->player->y += args->map->player->diry * 0.2;
		print_walls(args, args->map, args->map->player);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_S))
	{
		args->map->player->x -= args->map->player->dirx * 0.2;
		args->map->player->y -= args->map->player->diry * 0.2;
		print_walls(args, args->map, args->map->player);
	}
	// printf("x = %f,y = %f\n", args->map->player->x, args->map->player->y);

	// moves:
	// keydata.key == MLX_KEY_D
	// keydata.key == MLX_KEY_A
}
void	rotate(t_player *pl, double a)
{
	// float	old_dirx;
	// float	oldcamx;
	// float	v_cos;
	// float	v_sin;

	double	oldplanex;
	double	old_dirx;
	double	v_cos;
	double	v_sin;

	// const double	old_dirx = pl->dirx;
	// const double	oldcamx = pl->raydirx;
	// const double	v_cos = cosf(a);
	// const double	v_sin = sinf(a);

	old_dirx = pl->dirx;
	oldplanex = pl->planex;
	v_cos = cosf(a);
	printf("este el vcos = %f\n", v_cos);
	v_sin = sinf(a);

	printf("fin en rotate\n");
	pl->dirx = old_dirx * v_cos - pl->diry * v_sin;
	pl->diry = old_dirx * v_sin + pl->diry * v_cos;
	// pl->raydirx = oldplanex * v_cos - pl->raydiry * v_sin;
	// pl->raydiry = oldplanex * v_sin + pl->raydiry * v_cos;

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
				// printf("stepx = %d\n", pl->stepx);
				pl->mapx += pl->stepx;
				pl->side = 0;
			}
			else
			{
				// printf("stepy = %d\n", pl->stepy);
				pl->sidedisty += pl->deltadisty;
				// printf("x = %d y = %d\n", pl->mapx, pl->mapy);
				pl->mapy += pl->stepy;
				// printf("fuaaaax = %d y = %d\n", pl->mapx, pl->mapy);
				pl->side = 1;
			}
			if (map->map_fill[pl->mapy][pl->mapx] == '1') {
			// printf("x = %d y = %d, rayx: %f, rayy: %f\n", pl->mapx, pl->mapy, pl->raydirx, pl->raydiry);
				pl->hit = 1;
			}
		}
		// printf("sdx: %f, sdy: %f, ddx: %f, ddy: %f\n", pl->sidedistx, pl->sidedisty, pl->deltadistx, pl->deltadisty);
		if (pl->side == 0)
			pl->perpwalldist = pl->sidedistx - pl->deltadistx;
		else
			pl->perpwalldist = pl->sidedisty - pl->deltadisty;
		pl->lineheight = (int)(HEIGHT / (pl->perpwalldist));
		// printf("lineheight: %d, perpwalldist: %f\n", pl->lineheight, pl->perpwalldist);
		pl->drawstart = -pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawstart < 0)
			pl->drawstart = 0;
		pl->drawend = pl->lineheight / 2 + HEIGHT / 2;
		if (pl->drawend >= HEIGHT)
			pl->drawend = HEIGHT - 1;
// Diferenciar lado para pintar de un text o otra
		int color = pl->side ? 0xFBAED2FF : 0xfc030bff;
		print_vert_line(x, pl->drawstart, pl->drawend, color, args);
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
