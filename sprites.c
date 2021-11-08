/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:09:20 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 15:09:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_mon_list(t_data *data, int x, int y)
{
	int			i;

	i = 1;
	data->monster->m_row = x;
	data->monster->m_col = y;
	data->monster->dir_flag = 0;
	if (data->monster->next)
		data->monster = data->monster->next;
	i++;
}

void	monsters_sprites(t_data *data, int index)
{
	int			i;

	i = 0;
	while (data->monster->prev)
		data->monster = data->monster->prev;
	while (i < data->m_count)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img0,
			data->monster->m_col * 80, data->monster->m_row * 80);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgm[index],
			data->monster->m_col * 80, data->monster->m_row * 80);
		if (data->monster->next)
			data->monster = data->monster->next;
		i++;
	}
}

void	player_sprites(t_data *data, int index)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img0,
		data->player.p_col * 80, data->player.p_row * 80);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player
		.idle[index], data->player.p_col * 80 + 25, data
		->player.p_row * 80 + 2);
}

int	index_controller(int flag, int *i)
{
	*i = FPS - 1;
	if (flag)
		flag = 0;
	else
		flag = 1;
	return (flag);
}

int	loop_hook(t_data *data)
{
	static int	i;
	static int	index;
	int			n;
	static int	flag;

	i++;
	n = FPS;
	while (n < FPS * SPRITE_SIZE)
	{
		if (i == n && !flag)
			index++;
		else if (i == n && flag)
			index--;
		n += n;
	}
	if (data->m_count)
		mon_speed(data, i);
	if (i >= FPS * SPRITE_SIZE)
		flag = index_controller(flag, &i);
	player_sprites(data, index);
	if (data->m_count)
		monsters_sprites(data, index);
	return (0);
}
