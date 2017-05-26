# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 13:04:48 by jjacobi           #+#    #+#              #
#    Updated: 2017/05/26 01:16:14 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

SRC_FILES	= main.c get_ants_number.c parsing.c read_all.c analyse_line.c \
				reg_piece.c reg_connection.c store_piece_list.c \
				structure_data.c calc_shortest.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIRS		= -I ./includes -I ./libft/includes
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO	= echo
else
	ECHO	= echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.            \
		$(DEFAULT)"
	@($(MAKE) -C $(LIBFT_PATH))
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_PATH)/libft.a $(H_DIRS)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

%.o: $(SRC_FOLDER)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(CC) $(CFLAGS) -c -o $@ $< $(H_DIRS)


clean:
	@rm -rf $(OBJ)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@($(MAKE) -C $(LIBFT_PATH) $@)

fclean:
	@rm -rf $(NAME) $(OBJ)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@($(MAKE) -C $(LIBFT_PATH) $@)

re: fclean all

.PHONY: clean fclean re all
