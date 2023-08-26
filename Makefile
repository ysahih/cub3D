NAME = cub3D
HDR = cub3D.h
SRCS = main.c\
	load_texuters.c\
	Parsing/arguments_to_space.c Parsing/check_arguments.c Parsing/check_letters.c Parsing/directions_one.c Parsing/ft_strncmp.c\
	Parsing/parsing_one.c Parsing/remove_space_lines.c Parsing/remove_space_lines_one.c Parsing/rect.c Parsing/parsing.c\
	Parsing/ft_atoi.c Parsing/directions.c Parsing/check_inside.c Parsing/arguments_under_map.c\
	movement/movements_utils.c movement/movements.c\
	ray_casting/horizontal.c\
	ray_casting/hz_utils.c\
	ray_casting/ray_casting.c\
	ray_casting/ray_casting_utils.c\
	ray_casting/vertical.c\
	ray_casting/vt_utils.c\
	rendering/minimap.c\
	rendering/render.c\
	rendering/walls.c\
	utils/ft_memcpy.c\
	utils/ft_split.c\
	utils/ft_split_one.c\
	utils/ft_split_one_two.c\
	utils/ft_strdup.c\
	utils/ft_strjoin.c\
	utils/ft_strlen.c\
	utils/get_next_line.c\
	utils/get_next_line_utils.c\
	utils/storing.c\
	utils/utils.c\

CC = cc
OBJS = $(SRCS:%.c=%.o)
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  ../MLX42/build/libmlx42.a -Iinclude -lglfw -L "../homebrew/Cellar/glfw/3.3.8/lib" -o $(NAME) $^

%.o: %.c $(HDR)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all