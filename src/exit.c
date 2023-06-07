#include "../includes/cub3D.h"

void	exit_cub(t_args *args)
{
	if (args->no_text)
		mlx_delete_texture(args->no_text);
	if (args->so_text)
		mlx_delete_texture(args->so_text);
	if (args->we_text)
		mlx_delete_texture(args->we_text);
	if (args->ea_text)
		mlx_delete_texture(args->ea_text);
	exit(1);
}

void	free_structs(t_args	*args)
{
	free(args->map->player);
}