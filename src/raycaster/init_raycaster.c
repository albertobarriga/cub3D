#include "../../includes/cub3D.h"

void	init_args_mlx(t_args *args)
{
	args->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!args->mlx)
		free(args);
		// error y frees
	args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
	if (!args->img)
		free(args);
		// error y frees
}

void	init_args(t_args *args)
{
	mlx_loop_hook(args->mlx, &hook, args);
}

void	hook(void *param)
{
	t_args	*args;

	args = (t_args *) param;
	if (mlx_is_key_down(args->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(args->mlx);
	if (mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
		/*rote*/;
	if (mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
		/*rote*/;

	// moves:
	// keydata.key == MLX_KEY_D
	// keydata.key == MLX_KEY_A
}
