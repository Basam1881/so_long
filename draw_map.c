/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:26:35 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 16:14:29 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img1,
			y * 80, x * 80);
	else if (data->map[x][y] == '0' || data->map[x][y] == 'P' ||
		data->map[x][y] == 'C' || data->map[x][y] == 'E' ||
			data->map[x][y] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img0,
			y * 80, x * 80);
	if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgc,
			y * 80, x * 80);
	else if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imge,
			y * 80, x * 80);
}

void	loop_in_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->rows)
	{
		y = 0;
		while (y < data->cols)
		{
			draw_map(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgyb,
		data->cols * 80 / 2 - 88, 10);
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->cols * 80 / 2, 40,
		0x00FFFFFF, ft_itoa(data->steps));
}
