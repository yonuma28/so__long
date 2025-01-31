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
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
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

OBJS 		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
CC			=	cc
LIBX_FLAGS	=	libmlx/libmlx_Linux.a libmlx/libmlx.a -lX11 -lXext -lm -lz 
# Rules
all:		$(NAME)

bonus:      $(NAME_BONUS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

$(NAME_BONUS)    : $(OBJS_BONUS)
			$(CC) $(OBJS_BONUS) $(LIBX_FLAGS) -o $(NAME_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
