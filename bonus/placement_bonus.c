/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:12:13 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/26 20:08:25 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	place_player(t_data *game, int i, int j)
{
	if (game->dr == 0)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->pl, j * 50, i * 50);
	if (game->dr == 13)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->pb, j * 50, i * 50);
	if (game->dr == 2)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->pr, j * 50, i * 50);
	if (game->dr == 1)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->pf, j * 50, i * 50);
	game->y = i;
	game->x = j;
}

void	place_collectable(t_data *game, int i, int j)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->c, j * 50, i * 50);
	game->clt++;
}

void	place_exit(t_data *game, int i, int j)
{
	if (game->ex)
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->ex_o, j * 50, i * 50);
	else
		mlx_put_image_to_window(game->mlxptr,
			game->winptr, game->ex_c, j * 50, i * 50);
}

void	put_images(t_data *game)
{
	int	i;
	int	j;

	game->f = mlx_xpm_file_to_image(game->mlxptr,
			"textures/floor.xpm", &i, &j);
	game->w = mlx_xpm_file_to_image(game->mlxptr,
			"textures/wall.xpm", &i, &j);
	game->pf = mlx_xpm_file_to_image(game->mlxptr,
			"textures/playerfront.xpm", &i, &j);
	game->pb = mlx_xpm_file_to_image(game->mlxptr,
			"textures/playerback.xpm", &i, &j);
	game->pr = mlx_xpm_file_to_image(game->mlxptr,
			"textures/playerright.xpm", &i, &j);
	game->pl = mlx_xpm_file_to_image(game->mlxptr,
			"textures/playerleft.xpm", &i, &j);
	game->ex_c = mlx_xpm_file_to_image(game->mlxptr,
			"textures/exit_c.xpm", &i, &j);
	game->ex_o = mlx_xpm_file_to_image(game->mlxptr,
			"textures/exit_o.xpm", &i, &j);
	game->c = mlx_xpm_file_to_image(game->mlxptr,
			"textures/clt.xpm", &i, &j);
	put_images_enm(game);
	if (!game->f || !game->w || !game->pf || !game->pb || !game->pr
		|| !game->pl || !game->ex_c || !game->ex_o || !game->c)
		print_exit(game, "Error\nCheck the textures.");
}

void	add_window(t_data *game, int i, int j)
{
	game->clt = 0;
	while (++i < game->h_map)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->w, j * 50, i * 50);
			if (game->map[i][j] == 'C')
				place_collectable(game, i, j);
			if (game->map[i][j] == 'P')
				place_player(game, i, j);
			if (game->map[i][j] == 'E')
				place_exit(game, i, j);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->f, j * 50, i * 50);
		}
	}
}
