/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:14:51 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 15:12:11 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	monster_right_move(t_data *data)
{
	if (data->map[data->monster->m_row][data->monster->m_col + 1] == 'P')
	{
		printf("Such a loser");
		free_all (data);
	}
	data->map[data->monster->m_row][data->monster->m_col + 1] = data
		->map[data->monster->m_row][data->monster->m_col];
	data->map[data->monster->m_row][data->monster->m_col] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
		->img0, data->monster->m_col * 80, data->monster->m_row * 80);
	data->monster->m_col++;
}

void	monster_left_move(t_data *data)
{
	if (data->map[data->monster->m_row][data->monster->m_col - 1] == 'P')
	{
		printf("Such a loser");
		free_all (data);
	}
	data->map[data->monster->m_row][data->monster->m_col - 1] = data
		->map[data->monster->m_row][data->monster->m_col];
	data->map[data->monster->m_row][data->monster->m_col] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data
		->img0, data->monster->m_col * 80, data->monster->m_row * 80);
	data->monster->m_col--;
	data->monster->dir_flag = 1;
}

void	monster_moves(t_data *data)
{
	if ((data->map[data->monster->m_row][data->monster->m_col + 1] == '0'
		|| data->map[data->monster->m_row][data->monster->m_col + 1] == 'M'
		|| data->map[data->monster->m_row][data->monster->m_col + 1] == 'P')
		&& !data->monster->dir_flag)
		monster_right_move(data);
	else if (data->map[data->monster->m_row][data->monster->m_col - 1] == '0'
		|| data->map[data->monster->m_row][data->monster->m_col - 1] == 'M'
		|| data->map[data->monster->m_row][data->monster->m_col - 1] == 'P')
		monster_left_move(data);
	else
		data->monster->dir_flag = 0;
}

void	monsters_controller(t_data *data)
{
	int			i;

	i = 0;
	while (data->monster->prev)
		data->monster = data->monster->prev;
	while (i < data->m_count)
	{
		monster_moves (data);
		i++;
		if (data->monster->next)
			data->monster = data->monster->next;
	}
}

void	mon_speed(t_data *data, int i)
{
	int	n;

	n = SPEED;
	while (n < FPS * SPRITE_SIZE)
	{
		if (i == n)
			monsters_controller(data);
		n += SPEED;
	}
}
