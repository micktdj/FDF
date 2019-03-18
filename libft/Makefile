# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:19:48 by mtordjma          #+#    #+#              #
#    Updated: 2019/03/12 18:32:21 by piabdo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRCS = 		ft_atoi.c ft_strmapi.c ft_strndup.c get_next_line.c \
			ft_strcapitalize.c ft_lstmap.c ft_dlistaddt.c \
			ft_dlistaddh.c ft_dlistnew.c ft_putnbr.c ft_lstdel.c \
			ft_lstiter.c ft_strsub.c ft_swap.c \
			ft_foreach.c ft_lstnew.c ft_lstdelone.c ft_lstadd.c \
			ft_strmap.c ft_strjoin.c ft_strequ.c ft_itoa.c \
			ft_putnbr_fd.c ft_strsplit.c ft_strrev.c ft_striter.c \
			ft_strtrim.c ft_strnew.c ft_strdel.c ft_strnequ.c \
			ft_memdel.c ft_strclr.c ft_bzero.c ft_strnstr.c \
			ft_sort_integer_table.c ft_memmove.c ft_putendl_fd.c \
			ft_strstr.c ft_putstr_fd.c ft_isalnum.c ft_putendl.c \
			ft_memchr.c ft_strrchr.c ft_isalpha.c ft_striteri.c \
			ft_isascii.c ft_memcmp.c ft_memcpy.c ft_isdigit.c \
			ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
			ft_memalloc.c ft_memccpy.c ft_putchar_fd.c ft_memset.c \
			ft_putchar.c ft_putstr.c ft_strcat.c ft_strchr.c \
			ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c \
			ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_tolower.c ft_toupper.c

OBJ = $(SRCS:.c=.o)
INCLUDES = ./
PARAMS = -Wall -Wextra -Werror

GRN= \033[92m
YEL= \033[93m
DEF= \033[0m


.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "$(YEL)[libft]$(DEF) : Compilation..."
	@gcc $(PARAMS) -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(YEL)[libft]$(DEF) : Compilation                 $(GRN)[OK]$(DEF)"

clean:
	@rm -f *.o
	@echo "$(YEL)[libft]$(DEF) : Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YEL)[libft]$(DEF) : Full Cleaning               $(GRN)[OK]$(DEF)"

re: fclean all
