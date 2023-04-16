/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:58:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/21 16:14:20 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	copy_map(t_data *game)
{
	int		i;

	game->copy = (char **)malloc(game->h_map * sizeof(char *));
	i = -1;
	while (++i < game->h_map)
		game->copy[i] = ft_strdup(game->map[i]);
}

void	stor_x_in_map(char **map, int i, int j)
{
	if (map[i][j] == 'E' || map[i][j] == '1' || map[i][j] == 'x')
		return ;
	map[i][j] = 'x';
	stor_x_in_map(map, i, j - 1);
	stor_x_in_map(map, i, j + 1);
	stor_x_in_map(map, i - 1, j);
	stor_x_in_map(map, i + 1, j);
}

void	check_path(t_data *game)
{
	int	i;
	int	j;

	copy_map(game);
	stor_x_in_map(game->copy, game->start_r, game->start_c);
	i = -1;
	while (++i < game->h_map)
	{
		j = -1;
		while (++j < game->w_map)
		{
			if ((game->copy)[i][j] == 'C')
			{
				ft_printf("There is no path to collectible");
				exit_point(game);
			}
			if ((game->copy)[i][j] == 'E' && ((game->copy)[i][j + 1] != 'x'
			&& (game->copy)[i][j - 1] != 'x' && (game->copy)[i + 1][j] != 'x'
			&& (game->copy)[i - 1][j] != 'x'))
			{
				ft_printf("There is no path to exit");
				exit_point(game);
			}
		}
	}
}
