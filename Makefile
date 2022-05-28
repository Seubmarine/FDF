NAME = fdf

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRCS = fdf_init.c hooked.c draw.c parsing.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -L libft/ -lft -L ft_3d/ -lft_3d -lm

INCLUDES = -I minilibx-linux/ -I libft/includes -I ft_3d/ -I .

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MLX) LIBFT_3D $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBS)

LIBFT_3D:
	$(MAKE) -C ft_3d/

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

$(LIBFT):
	$(MAKE) -C $(LIBFT:libft.a=)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -c $(LIBS)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
