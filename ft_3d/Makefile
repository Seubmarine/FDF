NAME = libft_3d.a

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRCS = mesh.c matrix.c vec2di.c vec3d.c

OBJS = $(SRCS:.c=.o)

LIBS = -lm

INCLUDES = -I . -I .. -I ../minilibx-linux/

.PHONY: all clean fclean re


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
#$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)#

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -c $(LIBS)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
