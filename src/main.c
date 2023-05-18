#include "../includes/cub3D.h"
void	leaks(void)
{
	system("leaks -q cub3D");
}
int main(void)
{
    printf("linea mas larga: %i", longest_line("map.cub"));
    leaks();
}