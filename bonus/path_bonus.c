/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:58:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/25 16:55:32 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

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
	if (map[i][j] == 'E' || map[i][j] == '1'
	|| map[i][j] == 'x' || map[i][j] == 'e')
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

static int	n_len(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = n_len(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		len--;
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
