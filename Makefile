# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 13:28:19 by dbiguene          #+#    #+#              #
#    Updated: 2023/01/05 16:04:04 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	so_long

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	src/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #

SLX				=	slx/libslx.a

LIBFT			=	libft/libft.a

RE_LIBS			=	1

# ---- Files ---- #

HEADERS_LIST	=	so_long.h	assets_path.h	\
					typedefs.h

SRCS_LIST		=	so_long.c		parser.c	\
					map_checker.c	drawers.c	\

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

FRAMEWORKS		=	-Llibft -Lslx -lft -lslx

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
FRAMEWORKS		+= -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
FRAMEWORKS		+=	-framework OpenGL -framework AppKit
endif

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

opti			:
					${MAKE} re RE_LIBS=0 CFLAGS="-Wall -Wextra -Werror -fsanitize=address -O2"

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS} ${LIBFT} ${SLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}
					@echo "\033[0;32m [so_long] : ✔️ Successfully built so_long executable\033[1;36m ${NAME}\033[0;32m for \033[1;36m${UNAME} !\033[0;00m"
# ---- Lib rules ---- #

${SLX}			:
					make -C slx
					@echo "\033[0;32m [so_long/slx] : ✔️ Successfully built minilibx\033[1;36m ${@} !\033[0;00m"

${LIBFT}		:
					make -C libft
					@echo "\033[0;32m [so_long/libft] : ✔️ Successfully built libft\033[1;36m ${@} !\033[0;00m"

clean_libs		:
ifeq ($(RE_LIBS), 1)
					make -C slx clean
					@echo "\033[0;31m [so_long/slx] : ✔️ Successfully cleaned superlibx\033[1;36m slx/ !\033[0;00m"
					make -C libft fclean
					@echo "\033[0;31m [so_long/libft] : ✔️ Successfully cleaned libft\033[1;36m libft/ !\033[0;00m"
endif

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					@echo "\033[0;32m [so_long/bin] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;00m"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [so_long/bin] : ✔️ Successfully cleaned bin directories\033[1;36m bin/ !\033[0;00m"

fclean			:	clean clean_libs
					${RM} ${NAME}
					@echo "\033[0;31m [so_long] : ✔️ Successfully deleted executable\033[1;36m ${NAME} !\033[0;00m"
					${RM} ${SLX}
					@echo "\033[0;31m [so_long] : ✔️ Successfully deleted slx lib file\033[1;36m ${SLX} !\033[0;00m"

re				:	fclean all

run				:	all
					./${NAME}

test			:	${NAME}
					./${NAME} map.txt

norm			:
					norminette ${SRCS_LIST:%=${DIR_SRCS}%} ${HEADERS}

debug			:	${OBJS} ${HEADERS} ${LIBFT} ${SLX}
					gcc -g ${CFLAGS} -I ${DIR_HEADERS}. ${SRCS_LIST:%=${DIR_SRCS}%} ${FRAMEWORKS} -o ${NAME}
					@echo "\033[0;32m [so_long] : ✔️ Successfully built so_long debug executable\033[1;36m ${NAME}\033[0;32m for \033[1;36m${UNAME} !\033[0;00m"

.PHONY:	all clean fclean re run test norm clean_libs debug opti
.SILENT:
