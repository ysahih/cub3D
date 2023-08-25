NAME = cub3D
HDR = cube3d.h
SRCS = main.c \
	ft_memcpy.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c get_next_line_utils.c get_next_line.c \
	horizontal.c vertical.c ray_casting.c

CC = cc
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -L../MLX42/build -lmlx42 -L../homebrew/Cellar/glfw/3.3.8/lib -lglfw
MFLAGS = -I../homebrew/Cellar/glfw/3.3.8/include -I../MLX42/build

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MFLAGS) -o $(NAME) $^

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) $(MFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all