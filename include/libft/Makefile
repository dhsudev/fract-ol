# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 17:25:42 by ltrevin-          #+#    #+#              #
#    Updated: 2024/08/06 15:55:41 by ltrevin-         ###   ########.fr        #
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

########## GENERAL
NAME          = libft.a
HEADER_FILE   = libft.h
CC            = gcc
FLAGS         = -Wall -Wextra -Werror
AR            = ar rcs

##########  DIRECTORY ROUTES
OBJ_DIR       = ./obj
GNL_DIR		  = ./get_next_line
PRINTF_DIR    = ./ft_printf

##########  FILES
SRC_FILES     = ft_atoi.c       ft_isalpha.c    ft_memchr.c     ft_memset.c     ft_strlcat.c    ft_strrchr.c\
                ft_bzero.c      ft_isascii.c    ft_memcmp.c     ft_strchr.c     ft_strlcpy.c    ft_tolower.c\
                ft_calloc.c     ft_isdigit.c    ft_memcpy.c     ft_strlen.c     ft_toupper.c\
                ft_isalnum.c    ft_isprint.c    ft_memmove.c    ft_strdup.c     ft_strnstr.c    ft_substr.c\
                ft_strjoin.c    ft_itoa.c       ft_strtrim.c    ft_split.c      ft_strmapi.c    ft_striteri.c   ft_putchar_fd.c\
                ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c  ft_strncmp.c
SRC_BNS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
                ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS       = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRC_FILES)))
OBJECTS_BNS   = $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRC_BNS_FILES)))

GNL_FILES	  = get_next_line.c get_next_line_utils.c
GNL_FILES    := $(addprefix $(GNL_DIR)/, $(GNL_FILES))
GNL_OBJECTS  := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(GNL_FILES)))
GNL_HEADER    = $(GNL_DIR)/get_next_line.h
PRINTF_OBJECTS  = ft_numbers.o  ft_printf.o
PRINTF_OBJECTS  := $(addprefix $(PRINTF_DIR)/$(OBJ_DIR)/, $(PRINTF_OBJECTS)) 
DEPS		  = Makefile	$(HEADER_FILE) 


##########  RULES

all:  $(NAME) 

prueba:
	@echo $(GNL_FILES)
	@echo $(GNL_OBJECTS)

$(NAME): $(OBJECTS)  $(DEPS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo "📚 Library created!"

bonus: $(OBJECTS) $(OBJECTS_BNS) $(GNL_OBJECTS) $(DEPS) | ft_printf
	@$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BNS) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
	@echo "📚🌟 Libft with bonus, get_next_line & ft_printf created!"
	@touch bonus

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(GNL_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[0;32m🛠  \033[0;35m$(@F:.o=) \033[0;34mobject created!\033[0m"

ft_printf:
	@make -C $(PRINTF_DIR) --no-print-directory
clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧼 Removed object files from libft!"

fclean: clean
	@rm -f $(NAME) bonus
	@make -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "🧼 Removed $(NAME) file!"

re: fclean all

.PHONY: all clean fclean re ft_printf
