# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:19:47 by yonuma            #+#    #+#              #
#    Updated: 2025/06/14 17:05:57 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          =   so_long
NAME_BONUS    =   so_long_bonus
SRCS          =   main.c \
                  code_map/texture.c \
                  code_map/draw_map.c \
				  code_map/draw_map2.c \
                  check/map_check_init.c \
                  check/check_map_wall.c \
                  check/check_map_inclument.c \
                  check/check_map_char.c \
                  check/check_map_invalid.c \
				  check/utils.c \
				  free/free_map.c \
				  size/size.c \
                  move.c \
                  read_map.c \
				  read_map_utils.c \
                  gnl/get_next_line.c \
                  gnl/get_next_line_utils.c \
                  bonus/load_new_map.c 
                  
SRCS_BONUS    =   bonus/main_bonus.c \
                  bonus/move_bonus.c \
				  bonus/move_bonus2.c \
				  bonus/move_bonus3.c \
				  bonus/move_bonus4.c \
				  bonus/enemy_move.c \
				  bonus/enemy_utils.c \
				  bonus/main_move_func.c \
				  bonus/gravity.c \
                  code_map/texture.c \
                  code_map/draw_map.c \
				  code_map/draw_map2.c \
                  read_map.c \
				  read_map_utils.c \
				  free/free_map.c \
                  bonus/load_new_map.c \
                  bonus/enemy.c \
                  check/map_check_init.c \
                  check/check_map_wall.c \
                  check/check_map_inclument.c \
                  check/check_map_char.c \
                  check/check_map_invalid.c \
				  size/size.c \
                  gnl/get_next_line.c \
                  gnl/get_next_line_utils.c \
				  check/utils.c \
                  move.c

LIBFT_DIR     = libft
LIBFT_LIB     = $(LIBFT_DIR)/libft.a
LIBFT_INC     = -I$(LIBFT_DIR)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INC = -I$(FT_PRINTF_DIR)

OBJS          =   $(SRCS:.c=.o)
OBJS_BONUS    =   $(SRCS_BONUS:.c=.o)
CC            =   cc -Wextra -Wall -Werror
LIBX_FLAGS    =   libmlx/libmlx_Linux.a libmlx/libmlx.a -lX11 -lXext -lm -lz 

all:          $(NAME)

bonus:        $(NAME_BONUS)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(LIBX_FLAGS) -o $(NAME) $(LIBFT_INC) $(FT_PRINTF_INC)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(LIBX_FLAGS) -o $(NAME_BONUS) $(LIBFT_INC) $(FT_PRINTF_INC)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

norm:
	@norminette $(SRCS) $(SRCS_BONUS) so_long.h

fclean:			clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re bonus norm