# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:19:47 by yonuma            #+#    #+#              #
#    Updated: 2025/01/31 15:39:05 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minilibx_test
NAME_BONUS	=	minilibx_test_bonus
SRCS		=	main.c \
				texture.c \
				draw_map.c \
				map_check_init.c \
				move.c \
				read_map.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				bonus/load_new_map.c \
				itoa.c
				
SRCS_BONUS	=	bonus/main_bonus.c \
				bonus/move_bonus.c \
				texture.c \
				draw_map.c \
				read_map.c \
				bonus/load_new_map.c \
				bonus/enemy.c \
				map_check_init.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				itoa.c \
				move.c

LIBFT_DIR     = libft
LIBFT_LIB     = $(LIBFT_DIR)/libft.a
LIBFT_INC     = -I$(LIBFT_DIR)

OBJS 		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
CC			=	cc -Wextra -Wall -ggdb3
LIBX_FLAGS	=	libmlx/libmlx_Linux.a libmlx/libmlx.a -lX11 -lXext -lm -lz 

all:		$(NAME)

bonus:      $(NAME_BONUS)

$(NAME):	$(OBJS) $(LIBFT_LIB)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBX_FLAGS) -o $(NAME) $(LIBFT_INC)

$(NAME_BONUS)    : $(OBJS_BONUS) $(LIBFT_LIB)
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) $(LIBX_FLAGS) -o $(NAME_BONUS) $(LIBFT_INC)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
