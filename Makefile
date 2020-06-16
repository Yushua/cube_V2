# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 10:59:00 by ybakker       #+#    #+#                  #
#    Updated: 2020/06/16 13:23:31 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cube
SRC = ./srcs/cube_functions/main.c\
		./srcs/cube_functions/set_location.c\
		./srcs/cube_functions/texture.c\
		./srcs/cube_functions/keys.c\
		./srcs/cube_functions/error.c\
		./srcs/cube_functions/functions.c\
		./srcs/cube_functions/set_value.c\
		./srcs/cube_functions/map_check.c\
		./srcs/cube_functions/ft_floodfill.c\
		./srcs/cube_functions/raycasting_texture.c\
		./srcs/cube_functions/raycasting_sprites.c\
		./srcs/cube_functions/floor_casting.c\
		./srcs/cube_functions/create_bmp.c\
		./srcs/cube_functions/readmap/read_map.c\
		./srcs/cube_functions/readmap/get_map.c\
		./srcs/cube_functions/readmap/check_r.c\
		./srcs/cube_functions/readmap/check_no.c\
		./srcs/cube_functions/readmap/check_so.c\
		./srcs/cube_functions/readmap/check_s.c\
		./srcs/cube_functions/readmap/check_we.c\
		./srcs/cube_functions/readmap/check_ea.c\
		./srcs/cube_functions/readmap/check_f.c\
		./srcs/cube_functions/readmap/check_c.c\
		./srcs/cube_functions/readmap/space_cubemap.c\
		./srcs/get_next_line/get_next_line_utils.c\
		./srcs/get_next_line/get_next_line.c\

OBJ	= $(SRC:.c=.o)
CFLAGS = -g -Ofast
LIBFT = srcs/libft
MLX = srcs/mlx
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp srcs/mlx/libmlx.dylib ./libmlx.dylib
	@cp srcs/libft/libft.a ./libft.a
	@$(CC) -L srcs/mlx/ -lmlx -framework OpenGL -framework AppKit  \
	$(OBJ) libft.a -o $(NAME)
%.o: %.c
	@gcc $(CFLAGS) -I srcs/mlx -I srcs/libft -c $? -o $@
clean:
	@$(RM) $(OBJ)
	@$(RM) $(B_OBJ)
	@$(RM) bonus
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
fclean: clean
	@$(RM) $(BMP)
	@$(RM) $(NAME)
	@$(RM) libmlx.dylib
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
re: fclean all