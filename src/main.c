#include "../includes/cub3D.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

void	print_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}

void	free_matrix(char **matrix)
{
	int		i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_struct_map(t_map *map)
{
	free_matrix(map->map_fill);
	free(map->c);
	free(map->f);
	free(map->ea);
	free(map->so);
	free(map->we);
	free(map->no);

}

int	main(int argc, char **argv)
{
	atexit(leaks);
	t_map	map;
	//t_args		args;

	if (argc != 2)
		ft_help_argv("supported arguments\n");
	init_map(&map, argv[1]);
	if (checker_map(argv[1], &map))
		ft_help_argv("unsupported character\n");
	// printf("height = %i\n", map.height);
	// printf("width = %i\n", map.width);
	// printf("start_map  %i\n", map.start_map);
	// printf("NO  %s\n", map.no);
	// printf("WE   %s\n", map.we);
	// printf("EA   %s\n", map.ea);
	// printf("SO   %s\n", map.so);
	// printf("F    %s\n", map.f);
	// printf("C    %s\n", map.c);
	// printf("F color    %x\n", map.floor_color);
	print_matrix(map.map_fill);
	// init_args_mlx(&args);
	// init_args(&args, &map);
	// mlx_loop(args.mlx);
	// mlx_delete_image(args.mlx, args.img);
	// mlx_terminate(args.mlx);
	// printf("C color   %x\n", map.ceiling_color);
	free_struct_map(&map);
}

