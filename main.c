/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:08:27 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/08 16:09:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			fd;

	data.mlx_ptr = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd < 0)
	{
		printf ("Invalid map input\n");
		exit (1);
	}
	store_map(&data, fd);
	if (data.mlx_ptr == NULL)
		exit (1);
	data.mlx_win = mlx_new_window (data.mlx_ptr, data.cols * 80, data.rows * 80,
			"SO_LONG");
	if (data.mlx_win == NULL)
		exit (1);
	loop_in_map(&data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_hook (data.mlx_win, 2, 1L << 0, escape_me, &data);
	mlx_hook (data.mlx_win, 17, 0, free_all, &data);
	mlx_loop_hook(data.mlx_ptr, loop_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
