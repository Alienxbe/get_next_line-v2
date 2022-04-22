# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maykman <maykman@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 19:55:43 by maykman           #+#    #+#              #
#    Updated: 2022/04/22 20:24:46 by maykman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC			:=	@gcc
CFLAGS		:=	-Wall -Wextra -Werror
DEFINE		:=	-D BUFFER_SIZE=5

# VARS
LIB			:=	gnl
NAME		:=	${LIB}.a
BONUS		:=	${LIB}_bonus.a

# FILES
SRCS		=	get_next_line.c \
				get_next_line_utils.c
SRCS_BONUS	=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c
OBJS		=	$(addprefix mandatory/srcs/, ${SRCS:.c=.o})
OBJS_BONUS	=	$(addprefix bonus/srcs/, ${SRCS_BONUS:.c=.o})

%.o:		%.c
	${CC} ${CFLAGS} -c -I./mandatory/includes -I./bonus/includes ${DEFINE} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	@ar -rcs $@ $^

$(BONUS):		${OBJS_BONUS}
	@ar -rcs $@ $^

all:		${NAME}

clean:
	@rm -rf ${OBJS} ${OBJS_BONUS}

fclean:		clean
	@rm -rf ${NAME} ${BONUS}

re:			fclean all

.PHONY:		all clean fclean re
