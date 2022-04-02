SRC_NAME = so_long.c\
			draw_map.c\
			checks.c\
			keys.c\
			sprites.c\
			main.c\
			monster_moves.c\
			initialize.c

OBJ_NAME = $(SRC_NAME:.c=.o) 
MLX_DIR = ./minilibx
MLX_LIB = ./minilibx/libmlx.a
LIBFT_DIR = ./libft
LIBFT_LIB = ./libft/libft.a
CFLAG = -Wall -Wextra -Werror
DBG_FLAGS = -framework OpenGL -framework AppKit
NAME = ft_so_long.a
NEW_NAME = so_long.a
EXEC_NAME = so_long
 
.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ_NAME}
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(MLX_DIR) all
	gcc -c ${CFLAG} ${SRC_NAME}
	ar -r $(NAME) $(OBJ_NAME)
	libtool -static -o $(NEW_NAME) $(MLX_LIB) $(LIBFT_LIB) $(NAME)

linux: ${OBJ_NAME}
	$(MAKE) -C $(LIBFT_DIR)
	gcc $(CFLAG) $(SRC_NAME) ./libft/libft.a -L ./minilibx-linux -lmlx -lm -lX11 -lXext -o so_long

debug:
	gcc -g $(DBG_FLAGS) $(NEW_NAME) -o $(EXEC_NAME)

run: debug
	./$(EXEC_NAME) $(map)

bonus: ${NAME}

clean:
	rm -rf ${OBJ_NAME}
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f ${NAME} ${NEW_NAME}
	rm -f $(MLX_LIB)

e:
	rm $(EXEC_NAME)

cleanall: fclean e

re: fclean all

renux: fclean linux

reall: fclean all run