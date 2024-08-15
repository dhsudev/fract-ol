# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 15:40:29 by ltrevin-          #+#    #+#              #
#    Updated: 2024/08/15 20:08:39 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########## COLORS
RESET   		= \033[0m
BLACK   		= \033[0;30m
RED     		= \033[0;31m
GREEN   		= \033[0;32m
YELLOW  		= \033[0;33m
BLUE    		= \033[0;34m
MAGENTA 		= \033[0;35m
CYAN   			= \033[0;36m
WHITE   		= \033[0;37m

#Program name
NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall -g -fsanitize=address

# Minilibx
MLX_PATH	= include/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= include/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./include/\
				-I $(LIBFT_PATH)\
				-I $(MLX_PATH)

# Sources
SRC_PATH	=	src/
SRC			=	main.c math_utils.c mlx_utils.c 
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: banner $(MLX) $(LIBFT) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile include/fractol.h
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -C $(LIBFT_PATH) bonus --no-print-directory

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH) --no-print-directory
	@make fclean -C $(LIBFT_PATH) --no-print-directory

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

banner:
	@echo "\n$(CYAN)==============${BLUE} Welcome to Lua's Fract-ol $(CYAN)==============$(RESET)"
	@echo "	$(MAGENTA)	⠀⠀⠀⠀⠀⠀⠀⢀⣀⡤⠴⠶⠶⠒⠲⠦⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo '		⠀⠀⠀⠀⢀⡠⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠲⠤⣄⡀⠀⠀⠀⠀⠀'
	@echo '		⠀⠀⣀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⡿⠀⠀⠀⠀⠀'
	@echo '		⠀⢾⣅⡀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⢀⡦⠤⠄⠀⠀⢻⡀⠀⠀⠀⠀⠀'
	@echo '		⠀⠈⢹⡏⠀⠀⠐⠋⠉⠁⠀⠻⢿⠟⠁⠀⠀⢤⠀⠀⠠⠤⢷⣤⣤⢤⡄⠀'
	@echo '		⠀⠀⣼⡤⠤⠀⠀⠘⣆⡀⠀⣀⡼⠦⣄⣀⡤⠊⠀⠀⠀⠤⣼⠟⠀⠀⢹⡂'
	@echo '		⠀⠊⣿⡠⠆⠀⠀⠀⠈⠉⠉⠙⠤⠤⠋⠀⠀⠀⠀⠀⠀⡰⠋⠀⠀⠀⡼⠁'
	@echo '		⠀⢀⡾⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠜⠁⠀⠀⠀⣸⠁⠀'
	@echo '		⠀⠀⠀⡼⠙⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀'
	@echo '		⠀⢀⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀'
	@echo '		⠀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀'
	@echo '		⣾⠁⠀⢀⣠⡴⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀'
	@echo "		⠈⠛⠻⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀$(RESET)"


.PHONY: all re clean fclean banner

