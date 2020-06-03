# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruben <ruben@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 15:36:50 by agianico          #+#    #+#              #
#    Updated: 2020/06/03 12:28:45 by ruben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_c.c ft_printf_i.c ft_printf_p.c ft_printf_u.c ft_printf_s.c ft_printf_x.c ft_printf_x2.c ft_printf_%.c ft_printf_as.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

RM		=	rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
