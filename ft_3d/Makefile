NAME = ft_3d

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRCS = mesh.c matrix.c vec2di.c vec3d.c

OBJS = $(SRCS:.c=.o)

LIBS = 

INCLUDES = 

.PHONY: all clean fclean re


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -c

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
