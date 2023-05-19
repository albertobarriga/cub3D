#include "../includes/cub3D.h"
void	leaks(void)
{
	system("leaks -q cub3D");
}
int main(void)
{
	t_map		map;
	char		*path;
	t_args		args;

	path = "map.cub";
	width_map(path, &map);
	height_map(path, &map);
	printf("width: %i\n", map.width);
	printf("height: %i\n", map.height);
	init_args_mlx(&args);
	init_args(&args);
	mlx_loop(args.mlx);
	mlx_delete_image(args.mlx, args.img);
	mlx_terminate(args.mlx);
	leaks();
}