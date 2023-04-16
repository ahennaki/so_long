/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:13:03 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/25 17:29:36 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	check_format(char *str, t_data *game);

static int	strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

static int	add_line(t_data *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->h_map++;
	temp = (char **)malloc(sizeof(char *) * (game->h_map + 1));
	temp[game->h_map] = NULL;
	while (i < game->h_map - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

void	read_map(t_data *game, char **av)
{
	char	*line;

	check_format(av[1], game);
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0 || read(game->fd, 0, 0) < 0)
	{
		ft_printf("Error\nCheck the file.");
		exit_point(game);
	}
	line = get_next_line(game->fd);
	if (!line)
	{
		ft_printf("Error\nCheck the map.");
		exit_point(game);
	}
	while (1)
	{
		if (!add_line(game, line))
			break ;
		line = get_next_line(game->fd);
	}
	close (game->fd);
	game->w_map = strlen_map(game->map[0]);
}

void	check_map(t_data *game)
{
	int	i;

	i = -1;
	while (++i < game->h_map)
	{
		if (game->w_map != strlen_map(game->map[i]))
		{
			ft_printf("Error\nThe map is not rectangular.\n");
			exit_point(game);
		}
	}
}

void	check_format(char *str, t_data *game)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
	{
		ft_printf("Error\nThe format of the map is not *.ber\n");
		exit_point(game);
	}
}
