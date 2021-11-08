/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:10:49 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 15:13:36 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_after_key(t_data *data, char c)
{
	if (c == 'E' && data->stars == data->all_stars)
	{
		printf ("You get it this time dummy");
		free_all (data);
	}
	else if (c == 'C')
		data->stars++;
	else if (c == 'M')
	{
		printf ("Such a loser");
		free_all (data);
	}
}

void	right_key_check(t_data *data)
{
	if (data->map[data->player.p_row][data->player.p_col + 1] == 'E')
		check_after_key(data, 'E');
	else if (data->map[data->player.p_row][data
		->player.p_col + 1] == 'C')
		check_after_key(data, 'C');
	else if (data->map[data->player.p_row][data
		->player.p_col + 1] == 'M')
		check_after_key(data, 'M');
	if (!(data->map[data->player.p_row][data->player.p_col + 1] == 'E'))
	{
		data->map[data->player.p_row][data->player.p_col + 1] = data
			->map[data->player.p_row][data->player.p_col];
		data->map[data->player.p_row][data->player.p_col] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
			->img0, data->player.p_col * 80, data->player.p_row * 80);
		data->player.p_col++;
		data->steps++;
	}
}

void	down_key_check(t_data *data)
{
	if (data->map[data->player.p_row + 1][data->player.p_col] == 'E')
		check_after_key(data, 'E');
	else if (data->map[data->player.p_row + 1][data
		->player.p_col] == 'C')
		check_after_key(data, 'C');
	else if (data->map[data->player.p_row + 1][data
		->player.p_col] == 'M')
		check_after_key(data, 'M');
	if (!(data->map[data->player.p_row + 1][data->player.p_col] == 'E'))
	{
		data->map[data->player.p_row + 1][data->player.p_col] = data
			->map[data->player.p_row][data->player.p_col];
		data->map[data->player.p_row][data->player.p_col] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
			->img0, data->player.p_col * 80, data->player.p_row * 80);
		data->player.p_row++;
		data->steps++;
	}
}

void	left_key_check(t_data *data)
{
	if (data->map[data->player.p_row][data->player.p_col - 1] == 'E')
		check_after_key(data, 'E');
	else if (data->map[data->player.p_row][data
		->player.p_col - 1] == 'C')
		check_after_key(data, 'C');
	else if (data->map[data->player.p_row][data
		->player.p_col - 1] == 'M')
		check_after_key(data, 'M');
	if (!(data->map[data->player.p_row][data->player.p_col - 1] == 'E'))
	{
		data->map[data->player.p_row][data->player.p_col - 1] = data
			->map[data->player.p_row][data->player.p_col];
		data->map[data->player.p_row][data->player.p_col] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
			->img0, data->player.p_col * 80, data->player.p_row * 80);
		data->player.p_col--;
		data->steps++;
	}
}

void	up_key_check(t_data *data)
{
	if (data->map[data->player.p_row - 1][data->player.p_col] == 'E')
		check_after_key(data, 'E');
	else if (data->map[data->player.p_row - 1][data
		->player.p_col] == 'C')
		check_after_key(data, 'C');
	else if (data->map[data->player.p_row - 1][data
		->player.p_col] == 'M')
		check_after_key(data, 'M');
	if (!(data->map[data->player.p_row - 1][data->player.p_col] == 'E'))
	{
		data->map[data->player.p_row - 1][data->player.p_col] = data
			->map[data->player.p_row][data->player.p_col];
		data->map[data->player.p_row][data->player.p_col] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
			->img0, data->player.p_col * 80, data->player.p_row * 80);
		data->player.p_row--;
		data->steps++;
	}
}
