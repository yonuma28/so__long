# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 11:04:36 by yonuma            #+#    #+#              #
#    Updated: 2024/05/07 17:17:28 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -Wunused-function
NAME = libft.a
SRCS = ft_memcpy.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_memmove.c \
	   ft_strchr.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strrchr.c \
	   ft_memchr.c \
	   ft_tolower.c \
	   ft_memcmp.c \
	   ft_bzero.c \
	   ft_strncmp.c \
	   ft_strlcat.c \
	   ft_atoi.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_strnstr.c \
	   ft_memset.c \
	   ft_split.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_itoa.c \
	   ft_strtrim.c \
	   ft_strndup.c \
	   ft_toupper.c

BONUS =ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c
	   
OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)
INCLUDES = -I includes

all : $(NAME)

bonus : 
	@make all "OBJS = $(OBJS) $(OBJS_B)"

$(NAME) : $(OBJS) $(ONJS_B)
	ar rc $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDES)

clean : 
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re