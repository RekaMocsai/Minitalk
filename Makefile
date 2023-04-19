# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 11:57:01 by rmocsai           #+#    #+#              #
#    Updated: 2023/04/19 13:38:14 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_S	=	server.c

SRC_C	=	client.c

HEAD	=	minitalk.h

LIBFT	=	./libft/libft.a

NAME_S	=	server

NAME_C	=	client

BOTH	=	$(NAME_C) $(NAME_S)

OBJ_S		=	${SRC_S:.c=.o}

OBJ_C		=	${SRC_C:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

RM		=	rm -f

CLR_RM		= \033[0m
MAGENTA		= \033[0;95m
CYAN 		= \033[1;36m

.PHONY: all clean fclean re norm
.SILENT:

all: $(BOTH)

$(NAME_S): $(OBJ_S)
		$(MAKE) all -C ./libft
		cc -o $(NAME_S) $(OBJ_S) $(LIBFT)
		echo "$(MAGENTA)server $(CYAN)is ready$(CLR_RM)"

$(NAME_C): $(OBJ_C)
		$(MAKE) all -C ./libft
		cc -o $(NAME_C) $(OBJ_C) $(LIBFT)
		echo "$(MAGENTA)client $(CYAN)is ready$(CLR_RM)"
		
clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJ_S) $(OBJ_C)
		echo "$(MAGENTA)object files $(CYAN)deleted$(CLR_RM)"
		
fclean:	clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME_S) $(NAME_C)
		echo "$(MAGENTA)binary files $(CYAN)deleted$(CLR_RM)"
re:	fclean all

norm:	$(SRC_S) $(SRC_C)
		norminette -R CheckForbiddenSourceHeader $(SRC_S) $(SRC_C) $(HEAD)
