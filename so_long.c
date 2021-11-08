/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:09:09 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 16:06:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free (data->map[i]);
		i++;
	}
	free (data->map);
	if (data->m_count)
	{
		while (data->monster->prev)
			data->monster = data->monster->prev;
		i = 1;
		while (i < data->m_count)
		{
			if (data->monster->next)
				data->monster = data->monster->next;
			free (data->monster->prev);
			i++;
		}
		free (data->monster);
	}
	exit (0);
	return (0);
}

void	make_list(t_data *data)
{
	int	i;

	i = 1;
	data->monster = (t_monster *)malloc(sizeof(t_monster));
	if (!data->monster)
		return ;
	data->m_start = data->monster;
	data->monster->next = NULL;
	data->monster->prev = NULL;
	while (i < data->m_count)
	{
		data->monster->next = (t_monster *)malloc(sizeof(t_monster));
		if (!data->monster)
			return ;
		i++;
		data->monster->next->prev = data->monster;
		data->monster = data->monster->next;
	}
	data->monster->next = NULL;
	while (data->monster->prev)
		data->monster = data->monster->prev;
}

void	loop_in_m(t_data *data, char *m)
{
	int	i;

	i = 0;
	initialize_data(data);
	while (m[i])
	{
		if ((m[i] == '\n' && m[i] == m[i - 1]) || m[ft_strlen(m) - 1] == '\n')
			data->line_flag = 1;
		else if (m[i] == 'M')
			data->m_count++;
		i++;
	}
	if (data->m_count)
		make_list(data);
	free(m);
}

void	store_map(t_data *data, int fd)
{
	char	*tmp;
	int		len;
	char	*m;

	data->line_flag = 0;
	len = 1;
	m = (char *)malloc (sizeof(char));
	*m = 0;
	while (len)
	{
		tmp = (char *)malloc (sizeof(char) + 1);
		len = read(fd, tmp, 1);
		tmp[len] = 0;
		m = ft_strjoin(m, tmp);
	}
	data->map = ft_split(m, '\n');
	data->cols = ft_strlen(data->map[0]);
	while (data->map[len++])
		;
	data->rows = len - 1;
	loop_in_m(data, m);
	check_flag(data);
	close(fd);
}

int	key_hook(int keycode, t_data *data)
{
	char	*temp;

	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		if (keycode == D_KEY && data->map[data->player.p_row][data
			->player.p_col + 1] != '1')
			right_key_check(data);
		else if (keycode == S_KEY && data->map[data->player.p_row + 1][data
			->player.p_col] != '1')
			down_key_check(data);
		else if (keycode == A_KEY && data->map[data->player.p_row][data
			->player.p_col - 1] != '1')
			left_key_check(data);
		else if (keycode == W_KEY && data->map[data->player.p_row - 1][data
			->player.p_col] != '1')
			up_key_check(data);
		temp = ft_itoa(data->steps);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->imgyb,
			data->cols * 80 / 2 - 88, 10);
		mlx_string_put(data->mlx_ptr, data->mlx_win, data->cols * 80 / 2, 40,
			0x00FF0000, temp);
		free(temp);
		temp = NULL;
	}
	return (0);
}
