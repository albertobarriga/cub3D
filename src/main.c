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
	free_matrix(map->file_fill);
	free(map->c);
	free(map->f);
	free(map->ea);
	free(map->so);
	free(map->we);
	free(map->no);
	free(map->pj);
}

void	checker_errors_and_init(char *path_map, t_map *map)
{
	int	fd;

	if (checker_path_map(path_map))
		ft_help_argv("\033[0;31mError:\n supported file\n");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_help_argv("\033[0;31mError:\n invalid file\n");
	}
	close(fd);
	init_map(map, path_map);
	if (checker_map(path_map, map))
		ft_help_map("Error:\n unsupported character\n");
	if (!checker_colors(map->f) || !checker_colors(map->c))
		ft_help_colors("Error:\n unsupported colors\n");
	search_x_y(map);
		printf("free_road = %i\n", ft_free_road(map));
}

int	main(int argc, char **argv)
{
	t_map		map;
	//t_args		args;

	atexit(leaks);
	if (argc != 2)
		ft_help_argv("\033[0;31mError: unsupported arguments\n");
	checker_errors_and_init(argv[1], &map);
	print_matrix(map.map_fill);
	// init_args_mlx(&args);
	// init_args(&args, &map);
	// mlx_loop(args.mlx);
	// mlx_delete_image(args.mlx, args.img);
	// mlx_terminate(args.mlx);
	free_struct_map(&map);
}
