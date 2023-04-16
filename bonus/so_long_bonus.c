/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:13:07 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/26 19:53:54 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static void	*ft_memset(void *ptr, int c, size_t len)
{
	int	i;

	i = 0;
	while (len--)
		((unsigned char *)ptr)[i++] = (unsigned char)c;
	return (ptr);
}

void	check_errors(t_data *game)
{
	check_walls(game);
	check_chars(game);
	check_map(game);
}

int	exit_point(t_data *game)
{
	int	i;

	i = 0;
	if (game->winptr)
		mlx_destroy_window(game->mlxptr, game->winptr);
	free(game->mlxptr);
	while (i < game->h_map - 1)
		free(game->map[i++]);
	free(game->map);
	if (game->copy)
	{
		i = 0;
		while (i < game->h_map - 1)
			free(game->copy[i++]);
		free(game->copy);
	}
	exit(0);
}

void	pos_xy(t_data *game, int i, int j)
{
	game->y = i;
	game->x = j;
	game->count++;
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		ft_printf("Error\nCheck the arguments.");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_data));
	read_map(&game, av);
	check_errors(&game);
	check_path(&game);
	game.dr = 1;
	game.mlxptr = mlx_init();
	if (!game.mlxptr)
		exit_point(&game);
	game.winptr = mlx_new_window(game.mlxptr, (game.w_map * 50),
			(game.h_map * 50), "so_long");
	if (!game.winptr)
		exit_point(&game);
	put_images(&game);
	add_window(&game, -1, -1);
	mlx_key_hook(game.winptr, key_move, &game);
	mlx_loop_hook(game.mlxptr, add_enm, &game);
	mlx_hook(game.winptr, 17, 0, exit_point, &game);
	mlx_loop(game.mlxptr);
}
