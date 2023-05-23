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

void	init_args(t_args *args, t_map *map)
{
	mlx_loop_hook(args->mlx, &hook, args);
	// mlx_set_cursor_mode(args->mlx, MLX_MOUSE_DISABLED);
	print_back(args, map);
	// mlx_get_time;
	// mlx_loop(mlx);
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
				mlx_put_pixel(args->back, i, j, 0xFF0000FF);
			else
				mlx_put_pixel(args->back, i, j, 0x0000FFFF);
			i++;
		}
		j++;
	}
	mlx_image_to_window(args->mlx, args->back, 0, 0);
}
