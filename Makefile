################################################################################
#                          Makefile configuration                              #
################################################################################

NAME	= so_long
CFLAG	= -Wall -Wextra -Werror -g3
CC		= cc

################################################################################
#                                 Include                                      #
################################################################################

INCDIR = include
INC	= ${INCDIR}/so_long.h

################################################################################
#                                 Libft                                        #
################################################################################

LIBFT_FILE	= libft/libft.a
LIBFT_PATH	= libft/
LFLAG = -L./${LIBFT_PATH} -lft

################################################################################
#                                 Sources                                      #
################################################################################

SRCDIR = srcs

SRC = ${SRCDIR}/main.c \
		${SRCDIR}/manage_map/map_check.c \

################################################################################
#                                   Objects                                    #
################################################################################

OBJDIR = objs

OBJ = ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}

################################################################################
#                                   Colors                                     #
################################################################################

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m

################################################################################
#                                    Rules                                     #
################################################################################

all: ${LIBFT_FILE} ${NAME}

${NAME} : ${OBJ} 
	@${CC} ${CFLAG} -I ${INCDIR} -I./${LIBFT_PATH}include ${OBJ} ${LFLAG} -o ${NAME}
	@echo "${YELLOW}✰✰✰ Alright, you can use ${NAME} ✰✰✰ :D"

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAG} -I./include -I./${LIBFT_PATH}include -c $< -o $@
	@echo "${GREEN}***  Compilation success  ***"

${LIBFT_FILE} :
	@make -sC libft

clean: 
	@rm -rf ${OBJDIR}
	@echo "${PURPLE}► Cleaning done: ${OBJDIR} directory has been removed ◄"
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@rm -f ${NAME}
	@echo "${BLUE}► Fclean done: ${NAME} has been removed ◄"
	@make fclean -C ${LIBFT_PATH}

re: fclean all
	@echo "${CYAN}↻↻↻ Makefile has been re'd ↺↺↺ \o/"

.PHONY: all clean fclean re
