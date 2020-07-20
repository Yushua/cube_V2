# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ybakker <ybakker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/05 10:59:00 by ybakker       #+#    #+#                  #
#    Updated: 2020/07/20 12:12:59 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC = ./srcs/cube_functions/main.c\
		./srcs/cube_functions/create_bmp.c\
		./srcs/cube_functions/settings/error.c\
		./srcs/cube_functions/settings/input_file_to_image.c\
		./srcs/cube_functions/settings/key_input.c\
		./srcs/cube_functions/settings/keys.c\
		./srcs/cube_functions/settings/set_location.c\
		./srcs/cube_functions/settings/set_value_texture.c\
		./srcs/cube_functions/settings/set_value.c\
		./srcs/cube_functions/utills/check_fill.c\
		./srcs/cube_functions/utills/ft_check_empty_line.c\
		./srcs/cube_functions/utills/functions_pfour.c\
		./srcs/cube_functions/utills/functions_pthree.c\
		./srcs/cube_functions/utills/functions_ptwo.c\
		./srcs/cube_functions/utills/functions.c\
		./srcs/cube_functions/utills/map_check.c\
		./srcs/cube_functions/utills/utills_five.c\
		./srcs/cube_functions/casting/raycasting_sprites.c\
		./srcs/cube_functions/casting/raycasting_texture_input.c\
		./srcs/cube_functions/casting/raycasting_texture.c\
		./srcs/cube_functions/casting/render_next_frame_structure.c\
		./srcs/cube_functions/casting/texture.c\
		./srcs/cube_functions/readmap/get_info/ft_read_c.c\
		./srcs/cube_functions/readmap/get_info/ft_read_ea.c\
		./srcs/cube_functions/readmap/get_info/ft_read_f.c\
		./srcs/cube_functions/readmap/get_info/ft_read_no.c\
		./srcs/cube_functions/readmap/get_info/ft_read_r.c\
		./srcs/cube_functions/readmap/get_info/ft_read_s.c\
		./srcs/cube_functions/readmap/get_info/ft_read_so.c\
		./srcs/cube_functions/readmap/get_info/ft_read_we.c\
		./srcs/cube_functions/readmap/get_info/space_cubemap.c\
		./srcs/cube_functions/readmap/get_info/get_map.c\
		./srcs/cube_functions/readmap/ft_read_map.c\
		./srcs/cube_functions/readmap/ft_info_parser_check.c\
		./srcs/get_next_line/get_next_line_utils.c\
		./srcs/get_next_line/get_next_line.c\

SRC_BONUS = ./srcs_bonus/cube_functions_bonus/main_bonus.c\
		./srcs_bonus/cube_functions_bonus/create_bmp_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/error_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/input_file_to_image_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/key_input_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/keys_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/set_location_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/set_value_texture_bonus.c\
		./srcs_bonus/cube_functions_bonus/settings/set_value_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/check_fill_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/ft_check_empty_line_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/functions_pfour_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/functions_pthree_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/functions_ptwo_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/functions_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/map_check_bonus.c\
		./srcs_bonus/cube_functions_bonus/utills/utills_five_bonus.c\
		./srcs_bonus/cube_functions_bonus/casting/raycasting_sprites_bonus.c\
		./srcs_bonus/cube_functions_bonus/casting/raycasting_texture_input_bonus.c\
		./srcs_bonus/cube_functions_bonus/casting/raycasting_texture_bonus.c\
		./srcs_bonus/cube_functions_bonus/casting/render_next_frame_structure_bonus.c\
		./srcs_bonus/cube_functions_bonus/casting/texture_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_c_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_ea_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_f_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_no_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_r_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_s_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_so_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/ft_read_we_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/space_cubemap_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/get_info/get_map_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/ft_read_map_bonus.c\
		./srcs_bonus/cube_functions_bonus/readmap/ft_info_parser_check_bonus.c\
		./srcs/get_next_line/get_next_line_utils.c\
		./srcs/get_next_line/get_next_line.c\

OBJ	= $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g -Ofast
LIBFT = srcs/libft
MLX = mlx
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp mlx/libmlx.dylib ./libmlx.dylib
	@cp srcs/libft/libft.a ./libft.a
	@$(CC) -L mlx/ -lmlx -framework OpenGL -framework AppKit  \
	$(OBJ) libft.a -o $(NAME)
bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJ_BONUS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@cp mlx/libmlx.dylib ./libmlx.dylib
	@cp srcs/libft/libft.a ./libft.a
	@$(CC) -L mlx/ -lmlx -framework OpenGL -framework AppKit  \
	$(OBJ_BONUS) libft.a -o $(NAME_BONUS)
%.o: %.c
	@gcc $(CFLAGS) -I mlx -I srcs/libft -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@$(RM) bonus
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@$(RM) screen.bmp
fclean: clean
	@$(RM) $(BMP)
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) libmlx.dylib
	@$(RM) libft.a
	@make fclean -C $(LIBFT)
re: fclean all
