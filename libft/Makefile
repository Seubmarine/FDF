# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbousque <tbousque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 12:44:46 by tbousque          #+#    #+#              #
#    Updated: 2022/04/30 13:40:57 by tbousque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES		=	-I includes

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_realloc.c\
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strnjoin.c ft_strmapi.c ft_strtrim.c ft_isspace.c \
					ft_islower.c ft_isupper.c ft_abs.c ft_snullbase.c ft_isset.c ft_striteri.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c get_next_line/get_next_line.c \
					ft_strtoll.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror $(INCLUDES)

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

so:
		$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
		gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
