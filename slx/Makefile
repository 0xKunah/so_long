# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 13:28:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/12/15 14:07:20 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	libslx.a

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	src/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #


UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
OS				=	linux
endif

ifeq ($(UNAME), Darwin)
OS				=	macos
endif

MLX_PATH		=	./mlx/${OS}/

MLX				=	${MLX_PATH}libmlx.a


# ---- Files ---- #

HEADERS_LIST	=	slx.h

SRCS_LIST		=	slx.c		displayers.c	\
					loaders.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

AR				=	ar rcs

# ********* RULES ******** #

all				:	${NAME}

opti			:
					${MAKE} re CFLAGS="-Wall -Wextra -Werror -fsanitize=address -O2"

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					cp ${MLX} ${NAME}
					${AR} ${NAME} ${OBJS}
					@echo "\033[0;32m [${NAME}] : ✔️ Successfully built lib \033[1;36m ${NAME} !\033[0;37m"
# ---- Lib rules ---- #

${MLX}			:
					make -C ${MLX_PATH}
					@echo "\033[0;32m [${NAME}/mlx] : ✔️ Successfully built minilibx\033[1;36m mlx/${@} !\033[0;37m"

clean_libs		:
					make -C ${MLX_PATH} clean
					@echo "\033[0;31m [${NAME}/mlx] : ✔️ Successfully cleaned minilibx\033[1;36m mlx/ !\033[0;37m"

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS} ${MLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -I ${MLX_PATH} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					@echo "\033[0;32m [${NAME}/bin] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;37m"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [${NAME}/bin] : ✔️ Successfully cleaned bin directories\033[1;36m bin/ !\033[0;37m"

fclean			:	clean clean_libs
					${RM} ${NAME}
					@echo "\033[0;31m [${NAME}] : ✔️ Successfully deleted executable\033[1;36m ${NAME} !\033[0;37m"
					${RM} ${MLX}
					@echo "\033[0;31m [${NAME}] : ✔️ Successfully deleted mlx lib file\033[1;36m ${MLX} !\033[0;37m"

re				:	fclean all

norm			:
					norminette ${SRCS_LIST:%=${DIR_SRCS}%} ${HEADERS}

.PHONY:	all clean fclean re norm clean_libs opti
.SILENT:
