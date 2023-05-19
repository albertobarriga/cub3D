#include "../includes/cub3D.h"
void	leaks(void)
{
	system("leaks -q cub3D");
}
int main(void)
{
    t_map       map;
    char       *path;

    path = "map.cub";
    width_map(path, &map);
    height_map(path,& map);
	printf("width: %i\n", map.width);
	printf("height: %i\n", map.height);
    leaks();
}