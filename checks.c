/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:03:35 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 03:25:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape_me(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		free_all(data);
	}
	return (0);
}

void	add_flag(t_data *data, int x, int y)
{
	if (data->map[0][y] != '1' || data->map[x][0] != '1' ||
			data->map[data->rows - 1][y] != '1' ||
			data->map[x][data->cols - 1] != '1')
		data->no_walls = 1;
	if (data->map[x][y] == 'P')
	{
		data->player.p_row = x;
		data->player.p_col = y;
		data->p_flag++;
	}
	else if (data->map[x][y] == 'C')
		data->all_stars++;
	else if (data->map[x][y] == 'E')
		data->e_flag++;
	else if (data->map[x][y] == 'M')
		create_mon_list(data, x, y);
	else if (data->map[x][y] == '0' || data->map[x][y] == '1')
		;
	else
		data->unknown_flag = 1;
}

void	check_map(t_data *data)
{
	if (data->p_flag != 1 || !data->all_stars || data->e_flag != 1)
		printf ("Map must have 1 (E) and 1 (P) only, and at least 1 (C)");
	else if (data->unknown_flag)
		printf ("Map must include (0, 1, E, C, P, M) only");
	else if (data->no_walls)
		printf ("Map is not surrounded with walls");
	else if (data->line_flag)
		printf("Map should not have any gap or extra lines");
	else
		return ;
	exit (0);
}

void	check_flag(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		if (x)
		{
			if (ft_strlen(data->map[x]) != ft_strlen(data->map[x - 1]))
			{
				printf("Map is not rectangular");
				exit (0);
			}
		}
		while (data->map[x][y])
		{
			add_flag(data, x, y);
			y++;
		}
		x++;
	}
	check_map(data);
}
