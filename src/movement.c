/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:12:41 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/26 20:04:50 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_exit(t_data *game, char *str)
{
	ft_printf("%s\n", str);
	exit_point(game);
}

static int	play_move(t_data *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		if (game->clt != 0)
			return (0);
		ft_printf("YOU WIN.\n==================\nCONGRATULATIONS !!");
		exit_point(game);
	}
	if (game->map[i][j] == '0')
	{
		game->map[i][j] = 'P';
		game->y = i;
		game->x = j;
		game->count++;
	}
	if (game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->y = i;
		game->x = j;
		game->count++;
		if (!(--game->clt))
			game->ex = 1;
	}
	return (1);
}

static int	key_tb(t_data *game, int cmd)
{
	int	i;
	int	j;

	i = game->y;
	j = game->x;
	if (cmd == 13 || cmd == 126)
	{
		if (game->map[--i][j] == '1' || !play_move(game, i, j))
			return (0);
		game->map[i + 1][j] = '0';
		game->dr = 13;
	}
	else if (cmd == 1 || cmd == 125)
	{
		if (game->map[++i][j] == '1' || !play_move(game, i, j))
			return (0);
		game->map[i - 1][j] = '0';
		game->dr = 1;
	}
	ft_printf("Steps %i\n", game->count);
	return (1);
}

static int	key_lr(t_data *game, int cmd)
{
	int	i;
	int	j;

	i = game->y;
	j = game->x;
	if (cmd == 0 || cmd == 123)
	{
		if (game->map[i][--j] == '1' || !play_move(game, i, j))
			return (0);
		game->map[i][j + 1] = '0';
		game->dr = 0;
	}
	else if (cmd == 2 || cmd == 124)
	{
		if (game->map[i][++j] == '1' || !play_move(game, i, j))
			return (0);
		game->map[i][j - 1] = '0';
		game->dr = 2;
	}
	ft_printf("Steps %i\n", game->count);
	return (1);
}

int	key_move(int cmd, t_data *game)
{
	int	r;

	if (cmd == 53)
		exit_point(game);
	if (cmd == 13 || cmd == 126)
		r = key_tb(game, cmd);
	if (cmd == 1 || cmd == 125)
		r = key_tb(game, cmd);
	if (cmd == 0 || cmd == 123)
		r = key_lr(game, cmd);
	if (cmd == 2 || cmd == 124)
		r = key_lr(game, cmd);
	if (r)
		add_window(game);
	return (1);
}
