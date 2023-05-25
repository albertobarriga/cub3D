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

int	main(int argc, char **argv)
{
	t_map	map;

	//atexit(leaks);
	if (argc != 2)
		ft_help_argv("insufficient arguments\n");
	init_map(&map, argv[1]);
	print_matrix(map.map_fill);
	printf("start_map  %i\n", map.start_map);
	printf("NO  %s\n", map.no);
	printf("WE   %s\n", map.we);
	printf("EA   %s\n", map.ea);
	printf("SO   %s\n", map.so);
	printf("F    %s\n", map.f);
	printf("C    %s\n", map.c);
	printf("F color    %x\n", map.floor_color);
	printf("C color   %x\n", map.ceiling_color);
}


//TODO el parseo de cuantas letras y caracteres raros en el mapa