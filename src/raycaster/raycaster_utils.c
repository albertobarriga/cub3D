#include "../../includes/cub3D.h"

void	get_positions(t_player *pl, int x)
{
	pl->camerax = 2 * x / (double)WIDTH - 1;
	pl->raydirx = pl->dirx + pl->planex * pl->camerax;
	pl->raydiry = pl->diry + pl->planey * pl->camerax;
	pl->mapx = (int)(pl->x);
	pl->mapy = (int)(pl->y);
	pl->hit = 0;
	if (pl->raydirx == 0)
		pl->deltadistx = 1e30;
	else
		pl->deltadistx = fabs(1 / pl->raydirx);
	if (pl->raydiry == 0)
		pl->deltadisty = 1e30;
	else
		pl->deltadisty = fabs(1 / pl->raydiry);
}

void	get_step_sidedist(t_player *pl)
{
	if (pl->raydirx < 0)
	{
		pl->stepx = -1;
		pl->sidedistx = (pl->x - pl->mapx) * pl->deltadistx;
	}
	else
	{
		pl->stepx = 1;
		pl->sidedistx = (pl->mapx + 1.0 - pl->x) * pl->deltadistx;
	}
	if (pl->raydiry < 0)
	{
		pl->stepy = -1;
		pl->sidedisty = (pl->y - pl->mapy) * pl->deltadisty;
	}
	else
	{
		pl->stepy = 1;
		pl->sidedisty = (pl->mapy + 1.0 - pl->y) * pl->deltadisty;
	}
}

void	check_hit(t_player *pl, t_map *map)
{
	while (pl->hit == 0)
	{
		if (pl->sidedistx < pl->sidedisty)
		{
			pl->sidedistx += pl->deltadistx;
			pl->mapx += pl->stepx;
			pl->side = 0;
		}
		else
		{
			pl->sidedisty += pl->deltadisty;
			pl->mapy += pl->stepy;
			pl->side = 1;
		}
		if (map->map_fill[pl->mapy][pl->mapx] == '1')
			pl->hit = 1;
	}
}

void	get_linetoprint(t_player *pl)
{
	if (pl->side == 0)
		pl->perpwalldist = pl->sidedistx - pl->deltadistx;
	else
		pl->perpwalldist = pl->sidedisty - pl->deltadisty;
	pl->lineheight = (int)(HEIGHT / (pl->perpwalldist));
	pl->drawstart = -pl->lineheight / 2 + HEIGHT / 2;
	if (pl->drawstart < 0)
		pl->drawstart = 0;
	pl->drawend = pl->lineheight / 2 + HEIGHT / 2;
	if (pl->drawend >= HEIGHT)
		pl->drawend = HEIGHT - 1;
}
