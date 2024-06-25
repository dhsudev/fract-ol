# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 17:25:42 by ltrevin-          #+#    #+#              #
#    Updated: 2024/06/07 11:37:36 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########  VARS CONFIG
NAME          = libft.a
HEADER_FILE   = libft.h
CC            = gcc
FLAGS         = -Wall -Wextra -Werror
AR            = ar rcs
##########  VARS FILES
SRC_FILES     = ft_atoi.c       ft_isalpha.c    ft_memchr.c     ft_memset.c     ft_strlcat.c    ft_strrchr.c\
                ft_bzero.c      ft_isascii.c    ft_memcmp.c     ft_strchr.c     ft_strlcpy.c    ft_tolower.c\
                ft_calloc.c     ft_isdigit.c    ft_memcpy.c     ft_strlen.c     ft_toupper.c\
                ft_isalnum.c    ft_isprint.c    ft_memmove.c    ft_strdup.c     ft_strnstr.c    ft_substr.c\
                ft_strjoin.c    ft_itoa.c       ft_strtrim.c    ft_split.c      ft_strmapi.c    ft_striteri.c   ft_putchar_fd.c\
                ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c  ft_strncmp.c
SRC_BNS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
                ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJECTS       = $(SRC_FILES:.c=.o)
OBJECTS_BNS   = $(SRC_BNS_FILES:.c=.o)
##########  RULES
all:  $(NAME) 
$(NAME): $(OBJECTS)  $(HEADER_FILE) Makefile
	@$(AR) $(NAME) $(OBJECTS)
	@echo "📚 Library created!"
	
bonus: $(OBJECTS) $(OBJECTS_BNS) $(HEADER_FILE) Makefile
	@$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BNS)
	@echo "🔅 Library with bonus created!"
	@touch bonus

%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "🛠  $(@:.o=) object created!"

clean:
	@rm -f $(OBJECTS) $(OBJECTS_BNS)
	@echo "🧼 Removed object files from libft!"
	
fclean: clean
	@rm -f $(NAME) bonus
	@echo "🧼 Removed $(NAME) file!"
	
re: fclean all
.PHONY: all clean fclean re
