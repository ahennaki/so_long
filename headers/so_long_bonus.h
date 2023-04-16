/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:12:20 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/26 20:04:27 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"
# include "ft_printf.h"

typedef struct s_data
{
	int		start_r;
	int		start_c;
	int		fd;
	int		h_map;
	int		w_map;
	int		p_count;
	int		e_count;
	int		en_count;
	int		clt;
	int		x;
	int		y;
	int		count;
	int		dr;
	int		ex;

	char	**map;
	char	**copy;

	void	*en1;
	void	*en2;
	void	*en3;
	void	*en4;
	void	*en5;
	void	*en6;
	void	*en7;

	void	*f;
	void	*w;
	void	*pf;
	void	*pr;
	void	*pl;
	void	*pb;
	void	*ex_c;
	void	*ex_o;
	void	*c;
	void	*mlxptr;
	void	*winptr;

}	t_data;

int		exit_point(t_data *game);
int		key_move(int cmd, t_data *game);
int		add_enm(t_data *game);
void	read_map(t_data *game, char **argv);
void	add_window(t_data *game, int i, int j);
void	put_images(t_data *game);
void	check_errors(t_data *game);
void	check_walls(t_data *game);
void	check_chars(t_data *game);
void	check_map(t_data *game);
void	check_path(t_data *game);
void	place_player(t_data *game, int h, int w);
void	put_images_enm(t_data *game);
void	place_enm(t_data *game, int i, int j);
void	put_enm(t_data *game, void *ptr, int i, int j);
void	print_step(t_data *game);
void	pos_xy(t_data *game, int i, int j);
void	print_exit(t_data *game, char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);

#endif
