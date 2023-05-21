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

int main(void)
{
    t_map		map;
    char		*path;

    path = "map.cub";
    width_map(path, &map);
    //height_map(path,& map);
	map.map_fill = fill_map(path, &map);
	print_matrix(map.map_fill);
    leaks();
}
