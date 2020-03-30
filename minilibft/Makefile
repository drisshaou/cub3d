# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/17 06:57:02 by dhaouhao          #+#    #+#              #
#    Updated: 2020/03/18 00:02:30 by dhaouhao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minilibft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

SRCS		=	ft_atoi.c ft_putchar.c ft_split.c ft_strdup.c ft_strlen.c \
				ft_substr.c ft_isdigit.c ft_putstr.c ft_strcmp.c ft_strjoin.c \
				ft_strtrim.c get_next_line.c ft_memcpy.c

HEADER		=	minilibft.h

OBJS		=	${SRCS:.c=.o}

MINIFT_DIR	= ./

MINIFT_INC	= -I $(MINIFT_DIR)

.c.o:
			@$(CC) $(CFLAGS) -c $(MINIFT_INC) $< -o ${<:.c=.o}
			@echo "-c -o ${<:.c=.o} $<"

${NAME}:	${OBJS} ${HEADER}
			@echo "ar: creating ${NAME}"
			@ar rc $@ $^
			@echo "Archive library minilibft:	\033[1;32mOK\033[m"

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@echo "Removing minilibft objs"

fclean:		clean
			@rm -f ${NAME}
			@echo "Removing ${NAME}"

re:			fclean all

.PHONY:		fclean clean re all
