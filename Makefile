# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtordjma <mtordjma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:19:48 by mtordjma          #+#    #+#              #
#    Updated: 2019/03/12 17:45:01 by mtordjma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
PARAMS = -Wall -Wextra -Werror

INC_PATH = includes/
SRC_PATH = srcs/
OBJ_PATH = obj/

INC_NAME = fdf.h
LIBX_MACOS = -lmlx -framework OpenGL -framework AppKit
SRC_NAME =	ft_checkmap.c ft_print_error.c ft_stock.c \
			ft_draw.c ft_line.c ft_altitude_p.c \
			ft_altitude_i.c ft_trace.c ft_setui.c \
			ft_dlistdel.c ft_altitude_c.c main.c

OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I inc/ -I libft/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[fdf] : $(DEF)Compilation..."
	@make -C libft
	@$(CC) $(PARAMS) $(LIBX_MACOS) -o $(NAME) $(OBJ) $(INC) -L libft/ -lft
	@echo "$(RED)[fdf] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[fdf] :$(DEF) Compiling $@"
	@$(CC) $(PARAMS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[fdf] : $(DEF)Cleaning                    $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)[fdf] : $(DEF)Full Cleaning               $(GRN)[OK]$(DEF)"
re: fclean all