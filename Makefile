# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:51:39 by elvmarti          #+#    #+#              #
#    Updated: 2021/12/02 21:20:09 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philosophers.h

SRCS = srcs/philo.c \
		srcs/utils.c \
		srcs/create_list.c \
		srcs/time.c \
		srcs/do_things.c \
		srcs/lib.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra#-g3 -fsanitize=address

RM = rm -f


$(NAME): $(OBJS)
		@echo $(PURPLE)Compiling ... $(RESET)
		$(CC) ${CFLAGS} ${OBJS} -I $(HEADER) -o ${NAME}

all: $(NAME)

clean:
		@echo $(PURPLE)Cleaning ... $(RED)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all