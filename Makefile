# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:35:33 by ppizzo            #+#    #+#              #
#    Updated: 2021/10/09 20:54:03 by ppizzo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	so_long.c \
					so_long1.c \
					so_long2.c \
					so_long3.c \
					so_long4.c \
					so_long5.c \
					so_long6.c \
					so_long7.c \
					so_long8.c \
					so_long9.c \
					so_long10.c
					
OBJ_FILES		=	$(SRC_FILES:.c=.o)

NAME			= 	so_long

SO_LONG_LIB		=	libsolong.a

MLX_LIB			=	libmlx.dylib

CC				=	gcc

INCLUDE			=	-lmlx -framework OpenGL -framework AppKit

CFLAGS			=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -s -C minilibx_mms_20200219
	cp minilibx_mms_20200219/$(MLX_LIB) $(MLX_LIB)
	ar -rcs $(SO_LONG_LIB) $^
	$(CC) $(CFLAGS) so_long.c $(SO_LONG_LIB) $(INCLUDE) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_FILES)
	$(MAKE) clean -C minilibx_mms_20200219

fclean: clean
	rm -rf $(NAME)
	rm -rf $(SO_LONG_LIB)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
