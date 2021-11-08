/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:13:23 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 16:13:50 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_person_xpm_files(t_data *data)
{
	data->player.idle[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE0, &data->imgx, &data->imgy);
	data->player.idle[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE1, &data->imgx, &data->imgy);
	data->player.idle[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE2, &data->imgx, &data->imgy);
	data->player.idle[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE3, &data->imgx, &data->imgy);
	data->player.idle[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE4, &data->imgx, &data->imgy);
	data->player.idle[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE5, &data->imgx, &data->imgy);
	data->player.idle[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE6, &data->imgx, &data->imgy);
	data->player.idle[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE7, &data->imgx, &data->imgy);
	data->player.idle[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			IDLE8, &data->imgx, &data->imgy);
}

void	read_monster_xpm_files(t_data *data)
{
	data->imgm[0] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER0,
			&data->imgx, &data->imgy);
	data->imgm[1] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER1,
			&data->imgx, &data->imgy);
	data->imgm[2] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER2,
			&data->imgx, &data->imgy);
	data->imgm[3] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER3,
			&data->imgx, &data->imgy);
	data->imgm[4] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER4,
			&data->imgx, &data->imgy);
	data->imgm[5] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER5,
			&data->imgx, &data->imgy);
	data->imgm[6] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER6,
			&data->imgx, &data->imgy);
	data->imgm[7] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER7,
			&data->imgx, &data->imgy);
	data->imgm[8] = mlx_xpm_file_to_image(data->mlx_ptr, MONSTER8,
			&data->imgx, &data->imgy);
}

void	initialize_data(t_data *data)
{
	data->imgyb = mlx_xpm_file_to_image(data->mlx_ptr,
			Y_BTN, &data->imgx, &data->imgy);
	data->imge = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->imgx, &data->imgy);
	data->imgc = mlx_xpm_file_to_image(data->mlx_ptr, STAR,
			&data->imgx, &data->imgy);
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&data->imgx, &data->imgy);
	data->img0 = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY,
			&data->imgx, &data->imgy);
	read_person_xpm_files(data);
	read_monster_xpm_files(data);
	data->all_stars = 0;
	data->stars = 0;
	data->steps = 0;
	data->p_flag = 0;
	data->e_flag = 0;
	data->unknown_flag = 0;
	data->no_walls = 0;
	data->m_count = 0;
}
