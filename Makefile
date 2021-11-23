# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:51:39 by elvmarti          #+#    #+#              #
#    Updated: 2021/11/23 18:46:51 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

SRCS = srcs/philo.c \
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra#-g3 -fsanitize=address

RM = rm -f

LIBFTPATH = ./libft/

LIBFTNAME = libft.a

LIBFT = $(LIBFTPATH)$(LIBFTNAME)

$(NAME): $(OBJS) $(LIBFT)
		@echo $(PURPLE)Compiling ... $(RESET)
		$(CC) ${CFLAGS} ${OBJS} -I $(HEADER) -L. ${LIBFT} -o ${NAME}

$(LIBFT):		
		@echo $(PURPLE)Libft $(RESET)
		make re -C $(LIBFTPATH)

all: $(NAME)

debug: $(FU_ELVIRA)

clean:
		@echo $(PURPLE)Cleaning ... $(RED)
		$(RM) $(OBJS) $(LIBFTPATH)*.o

fclean: clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all