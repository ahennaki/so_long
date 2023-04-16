/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:46:26 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/26 20:08:35 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	put_images_enm(t_data *game)
{
	int	i;
	int	j;

	game->en1 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm1.xpm", &i, &j);
	game->en2 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm2.xpm", &i, &j);
	game->en3 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm3.xpm", &i, &j);
	game->en4 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm4.xpm", &i, &j);
	game->en5 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm5.xpm", &i, &j);
	game->en6 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm6.xpm", &i, &j);
	game->en7 = mlx_xpm_file_to_image(game->mlxptr,
			"textures/enm7.xpm", &i, &j);
	if (!game->en1 || !game->en2 || !game->en3 || !game->en4
		|| !game->en5 || !game->en6 || !game->en7)
		print_exit(game, "Error\nCheck the textures.");
}

void	put_enm(t_data *game, void *ptr, int i, int j)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, ptr, j * 50, i * 50);
}

void	place_enm(t_data *game, int i, int j)
{
	static int	x;

	if (x <= 50)
		put_enm(game, game->en1, i, j);
	if (x > 50 && x <= 75)
		put_enm(game, game->en2, i, j);
	if (x > 75 && x <= 100)
		put_enm(game, game->en3, i, j);
	if (x > 100 && x <= 125)
		put_enm(game, game->en4, i, j);
	if (x > 125 && x <= 150)
		put_enm(game, game->en5, i, j);
	if (x > 150 && x <= 175)
		put_enm(game, game->en6, i, j);
	if (x > 175 && x <= 200)
		put_enm(game, game->en7, i, j);
	if (x > 200)
		x = 0;
	x++;
}

int	add_enm(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->h_map)
	{
		j = -1;
		while (++j < game->w_map)
		{
			if (game->map[i][j] == 'e')
				place_enm(game, i, j);
		}
	}
	return (1);
}

void	print_step(t_data *game)
{
	char	*step;

	game->map[0][0] = ' ';
	mlx_put_image_to_window(game->mlxptr, game->winptr, game->w, 0, 0);
	step = ft_itoa(game->count);
	mlx_string_put(game->mlxptr, game->winptr, 20, 30, 0xFDFBFB, step);
	free(step);
}
