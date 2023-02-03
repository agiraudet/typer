# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 15:43:27 by agiraude          #+#    #+#              #
#    Updated: 2023/02/03 19:05:36 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	typer

BUILD_DIR	:=	./build

SRCS_DIR	:=	./srcs

SRCS		:=	main.c \
				vec.c \
				stat.c

OBJS		:=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

INC_DIRS	:=	./includes 

INC_FLAGS	:=	$(addprefix -I, $(INC_DIRS))

DEPS		:= 	-lncurses

CFLAGS		:=	$(INC_FLAGS) -Wall -Wextra -Werror -g

CC			:= clang

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
