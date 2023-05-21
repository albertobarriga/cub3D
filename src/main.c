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

    if (argc != 2)
        return 0;
    init_map(&map, argv[1]);
	print_matrix(map.map_fill);
    printf("%s\n", map.NO);
    printf("%s\n", map.WE);
    printf("%s\n", map.EA);
    printf("%s\n", map.SO);
    leaks();
}
