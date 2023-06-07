#include "../../includes/cub3D.h"


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
	if (args->map->map_fill[(int)args->map->player->y]
		[(int)(new_x + args->map->player->dirx / 1e5)] != '1')
		args->map->player->x = new_x;
	if (args->map->map_fill[(int)(new_y + args->map->player->diry / 1e5)]
		[(int)args->map->player->x] != '1')
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