#include "../../includes/cub3D.h"

void	init_args_mlx(t_args *args)
{
	args->no_text = NULL;
	args->so_text = NULL;
	args->we_text = NULL;
	args->ea_text = NULL;
	args->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!args->mlx)
	{
		free(args);
		exit(0);
	}
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	if (!args->img)
	{
		free(args);
		exit(0);
	}
}

void	init_args(t_args *args, t_map *map)
{
	mlx_load_text(args, map);
	mlx_loop_hook(args->mlx, &hook, args);
	// mlx_set_cursor_mode(args->mlx, MLX_MOUSE_DISABLED);
	print_back(args, map);
	init_player(map);
	print_walls(args, map, map->player);
}

void	init_player(t_map	*map)
{
	map->player = malloc(sizeof(t_player));
	map->player->x = map->pj->x;
	map->player->y = map->pj->y;
	map->player->dirx = 0;
	map->player->diry = 0;
	map->player->planey = 0;
	map->player->planex = 0;
	if (map->pj->orientation == 'N')
		map->player->diry = -1;
	else if (map->pj->orientation == 'S')
		map->player->diry = 1;
	else if (map->pj->orientation == 'E')
		map->player->dirx = 1;
	else if (map->pj->orientation == 'W')
		map->player->dirx = -1;
	if (map->pj->orientation == 'N')
		map->player->planex = 0.66;
	else if (map->pj->orientation == 'S')
		map->player->planex = -0.66;
	else if (map->pj->orientation == 'E')
		map->player->planey = 0.66;
	else if (map->pj->orientation == 'W')
		map->player->planey = -0.66;
}
