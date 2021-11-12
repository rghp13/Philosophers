# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 16:02:48 by rponsonn          #+#    #+#              #
#    Updated: 2021/11/12 17:43:04 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[32m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m
CYAN = \033[36m

PATH_SRC		=	./
PATH_HEAD		=	./

SRC_NAME		=	main.c parse.c ft_atoi.c error.c utils.c init.c thread.c \
					print.c
NAME			=	philo
OBJ_NAME		=	$(SRC_NAME:.c=.o)
CC				=	gcc
RM				=	rm -f
CFLAG			=	-Wall -Wextra -Werror -pthread
SRC				=	$(addprefix $(PATH_SRC)/,$(SRC_NAME))
OBJ				=	$(addprefix $(PATH_SRC)/,$(OBJ_NAME))

.c.o:
				@${CC} ${CFLAG} -I${PATH_HEAD} -c $< -o ${<:.c=.o}
				@echo "${GREEN}[ OK ] ${<:.s=.o}${NC}"

${NAME}:		${OBJ}
				@${CC} $^ -o $@ ${CFLAG}
				@echo "${GREEN}[ COMPLETE ]${NC}"
all:			${NAME}

clean:
				@${RM} ${OBJ}
				@echo "\n${GREEN}[ OK ]${RED}    *.o files deleted${NC}"
fclean:			clean
				@${RM} ${NAME}
				@echo "${GREEN}[ OK ]${RED}    ${NAME}    deleted${NC}"
re:				fclean ${NAME}
.PHONY:			all clean fclean re
