NAME = fdf

CC = gcc

CFLAGS = -g3 -Ofast -Wall -Werror -Wextra

SRCS = fdf_init.c draw.c mlx_event.c $(wildcard parser/*.c) $(wildcard ft_3d/*.c)

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

#LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -L ft_3d/ -lft_3d -L libft/ -lft -lm
LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -L libft/ -lft -lm

INCLUDES = -I . -I minilibx-linux/ -I libft/includes -I ft_3d/ -I parser/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBS)

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

$(LIBFT):
	$(MAKE) -C $(LIBFT:libft.a=)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
