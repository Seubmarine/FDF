NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = fdf_init.c

OBJS = $(SRCS:.c=.o)

MLX = minilibx-linux/libmlx.a

LIBS = -L minilibx-linux/ -lmlx -lXext -lX11

INCLUDES = -I minilibx-linux/

.PHONY: all clean fclean re


all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX:libmlx.a=)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $< -c

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
