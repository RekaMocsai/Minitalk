# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 11:57:01 by rmocsai           #+#    #+#              #
#    Updated: 2023/01/20 11:58:51 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	server.c client.c

HEAD	=	minitalk.h

NAME	=	minitalk.a

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

EXE		=	a.out

.PHONY: all clean fclean re norm

%.o:	%.c
		${CC} $(CFLAGS) -c $< -o $@
		
all: $(NAME)

$(NAME): ${OBJ}
		ar -crs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME) $(EXE)

re:	fclean all

norm:	$(SRC)
		norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)

test: $(NAME)
		@$(CC) $(CFLAGS) $(NAME)
		./a.out
