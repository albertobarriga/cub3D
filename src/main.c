#include "../includes/cub3D.h"
void	leaks(void)
{
	system("leaks -q cub3D");
}


void print_matrix(char **matrix)
{
	int i = -1;
	while(matrix[++i])
		printf("%s\n", matrix[i]);
}

int main(int argc, char **argv)
{
    t_map		map;
	t_args		args;

    if (argc != 2)
        return 0;
    init_map(&map, argv[1]);
	print_matrix(map.map_fill);
    printf("NO  %s\n", map.NO);
    printf("WE   %s\n", map.WE);
    printf("EA   %s\n", map.EA);
    printf("SO   %s\n", map.SO);
    printf("F    %s\n", map.F);
    printf("C    %s\n", map.C);
	init_args_mlx(&args);
	init_args(&args);
	mlx_loop(args.mlx);
	mlx_delete_image(args.mlx, args.img);
	mlx_terminate(args.mlx);
    leaks();
}

