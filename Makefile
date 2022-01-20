NAME = fdf

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRCS = fdf_init.c hooked.c draw.c parsing.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -L libft/ -lft

INCLUDES = -I minilibx-linux/ -I libft/includes

.PHONY: all clean fclean re


all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

$(LIBFT):
	$(MAKE) -C $(LIBFT:libft.a=)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $< -c

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
