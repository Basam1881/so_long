/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:24:58 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/02 22:45:06 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# define FPS 2
# define SPEED 5
# define SPRITE_SIZE 9


/** For Mac**/
# define ESC_KEY 53
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0
# define W_KEY 13
/**       **/


/** For Linux**/
// # define ESC_KEY 65307
// # define D_KEY 100
// # define S_KEY 115
// # define A_KEY 97
// # define W_KEY 119
/**       **/

# define WIN_KEY -272630608
# define Y_BTN "./images/yellow_button.xpm"
# define EXIT "./images/exit.xpm"
# define STAR "./images/star.xpm"
# define MONSTER0 "./images/monster0.xpm"
# define MONSTER1 "./images/monster1.xpm"
# define MONSTER2 "./images/monster2.xpm"
# define MONSTER3 "./images/monster3.xpm"
# define MONSTER4 "./images/monster6.xpm"
# define MONSTER5 "./images/monster7.xpm"
# define MONSTER6 "./images/monster8.xpm"
# define MONSTER7 "./images/monster9.xpm"
# define MONSTER8 "./images/monster10.xpm"
# define WALL "./images/wall.xpm"
# define EMPTY "./images/empty.xpm"
# define IDLE0 "./images/idle0.xpm"
# define IDLE1 "./images/idle1.xpm"
# define IDLE2 "./images/idle2.xpm"
# define IDLE3 "./images/idle3.xpm"
# define IDLE4 "./images/idle4.xpm"
# define IDLE5 "./images/idle5.xpm"
# define IDLE6 "./images/idle6.xpm"
# define IDLE7 "./images/idle7.xpm"
# define IDLE8 "./images/idle8.xpm"

typedef struct s_monster
{
	int					m_row;
	int					m_col;
	int					dir_flag;
	struct s_monster	*next;
	struct s_monster	*prev;
}				t_monster;

typedef struct s_player
{
	void		*idle[SPRITE_SIZE];
	int			p_row;
	int			p_col;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			rows;
	int			cols;
	t_player	player;
	t_monster	*monster;
	t_monster	*m_start;
	void		*imgc;
	void		*imge;
	void		*img1;
	void		*img0;
	void		*imgyb;
	void		*imgm[SPRITE_SIZE];
	int			imgx;
	int			imgy;
	int			stars;
	int			all_stars;
	int			steps;
	int			m_count;
	int			p_flag;
	int			e_flag;
	int			unknown_flag;
	int			no_walls;
	int			line_flag;
}				t_data;
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	check_after_key(t_data *data, char c);
void	right_key_check(t_data *data);
void	down_key_check(t_data *data);
void	left_key_check(t_data *data);
void	up_key_check(t_data *data);
void	initialize_data(t_data *data);
void	draw_map(t_data *data, int x, int y);
void	loop_in_map(t_data *data);
int		loop_hook(t_data *data);
int		escape_me(int keycode, t_data *data);
int		close_me(void);
void	add_flag(t_data *data, int x, int y);
void	check_map(t_data *data);
void	check_flag(t_data *data);
int		key_hook(int keycode, t_data *data);
void	store_map(t_data *data, int fd);
void	create_mon_list(t_data *data, int x, int y);
int		free_all(t_data *data);
void	mon_speed(t_data *data, int i);

#endif