/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:12:53 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/25 16:14:25 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	horizontalwall(t_data *game)
{
	int	i;
	int	j;

	i = game->w_map;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->h_map - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	j = game->w_map;
	while (++i < game->h_map)
	{
		if (!(game->map[i][0] == '1'
			&& game->map[i][j - 1] == '1'))
			return (0);
	}
	return (1);
}

void	check_walls(t_data *game)
{
	int	hw;
	int	vw;

	vw = verticalwall(game);
	hw = horizontalwall(game);
	if (!vw || !hw
		|| game->map[game->h_map - 1][game->w_map] == '\n')
	{
		ft_printf("Error\nCheck the map.\n");
		exit_point(game);
	}
}

static void	count_checker(t_data *game, int i, int j)
{
	if (game->map[i][j] != '1' && game->map[i][j] != '0'
	&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
	&& game->map[i][j] != 'C' && game->map[i][j] != '\n')
	{
		ft_printf("Error\n* %c * must not exist in map.", game->map[i][j]);
		exit_point(game);
	}
	if (game->map[i][j] == 'C')
			game->clt++;
	if (game->map[i][j] == 'P')
	{
		game->p_count++;
		game->start_r = i;
		game->start_c = j;
	}
	if (game->map[i][j] == 'E')
		game->e_count++;
}

void	check_chars(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->h_map - 1)
	{
		j = -1;
		while (++j <= game->w_map)
		{
			count_checker(game, i, j);
		}
	}
	if (!(game->p_count == 1 && game->clt >= 1
			&& game->e_count == 1))
	{
		ft_printf("Something is wrong!\nCheck the map.\n");
		exit_point(game);
	}
}
