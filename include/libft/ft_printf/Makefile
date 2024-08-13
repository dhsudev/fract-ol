# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 16:20:31 by ltrevin-          #+#    #+#              #
#    Updated: 2024/08/06 15:47:51 by ltrevin-         ###   ########.fr        #
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

BOLD    		= \033[1m
UNDERLINE 		= \033[4m

##########  VARS CONFIG
NAME            = libftprintf.a
HEADER_FILE     = ft_printf.h
CC              = gcc
FLAGS           = -Wall -Wextra -Werror
AR              = ar rcs

##########  PATHS
SRCS_PATH       = ./src
INCLUDE_PATH    = ./include
OBJ_DIR         = ./obj

##########  VARS FILES
SRC_FILES       = ft_printf.c ft_numbers.c
OBJECTS         = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

##########  RULES
all: $(NAME)

$(NAME): $(INCLUDE_PATH)/$(HEADER_FILE) $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo "$(BOLD)$(YELLOW)🔅 Printf is ready to work!$(RESET)"

$(OBJ_DIR)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
	@echo "$(GREEN)🛠  $(MAGENTA)$(@F:.o=) $(BLUE)object created!$(RESET)"

.PHONY: all clean fclean re

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧼 Removed object files from printf!"

fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all
