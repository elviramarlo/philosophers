# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:51:39 by elvmarti          #+#    #+#              #
#    Updated: 2021/12/12 21:08:46 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_DEBUG = philo_debug

HEADER = philosophers.h

SRCS = srcs/philo.c \
		srcs/utils.c \
		srcs/create_list.c \
		srcs/death.c \
		srcs/do_things.c \
		srcs/lib.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra#-g3 -fsanitize=address

RM = rm -f

$(NAME): $(OBJS)
		@echo - Compiling -
		$(CC) ${CFLAGS} ${OBJS} -I $(HEADER) -o ${NAME}

debug:
		@echo - Compiling Debug -
		$(CC) ${CFLAGS} ${SRCS} -I $(HEADER) -o ${NAME_DEBUG} -g
all: $(NAME)

clean:
		@echo - Cleaning -
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all