################################################################################
#                          Makefile configuration                              #
################################################################################

NAME		= so_long
NAME_BONUS	= so_long_bonus
CFLAG		= -Wall -Wextra -Werror -g3
CC			= cc

################################################################################
#                                 Include                                      #
################################################################################

INCDIR 	 		= include
INC	   	 		= ${INCDIR}/so_long.h
INCBONUS 		= ${INCDIR}/so_long_bonus.h
INCLUDES 		= -I ${INCDIR} -I./${LIBFT_PATH}include -I./${MINILBX_PATH}
INCLUDES_BONUS 	= -I ${INCDIR} -I./${LIBFT_PATH}include -I./${MINILBX_PATH}

################################################################################
#                                 Libft                                        #
################################################################################

LIBFT_FILE	= libft/libft.a
LIBFT_PATH	= libft/
LFLAG 		= -L./${LIBFT_PATH} -lft

################################################################################
#                              MiniLibx                                        #
################################################################################

MINILBX_FILE	= mlx-linux/libmlx_Linux.a
MINILBX_PATH	= mlx-linux/
MLXFLAG 		= -L./${MINILBX_PATH} -lmlx -lXext -lX11 -lm

################################################################################
#                                 Sources                                      #
################################################################################

SRCDIR 		= srcs

SRC			=	${SRCDIR}/mandatory/main.c \
				${SRCDIR}/mandatory/manage_map/map_ber.c \
				${SRCDIR}/mandatory/manage_map/map_init.c \
				${SRCDIR}/mandatory/manage_map/map_parsing.c \
				${SRCDIR}/mandatory/manage_map/map_error.c \
				${SRCDIR}/mandatory/manage_map/map_path.c \
				${SRCDIR}/mandatory/manage_map/valid_path.c \
				${SRCDIR}/mandatory/sprites/images_init.c \
				${SRCDIR}/mandatory/sprites/close_and_free.c \
				${SRCDIR}/mandatory/sprites/check_image.c \
				${SRCDIR}/mandatory/action/move.c \
				${SRCDIR}/mandatory/action/exit_handle.c \

BONUSDIR	= 	${SRCDIR}/bonus

BONUS_SRC 	=	${BONUSDIR}/main_bonus.c \
				${BONUSDIR}/manage_map/map_ber_bonus.c \
				${BONUSDIR}/manage_map/map_init_bonus.c \
				${BONUSDIR}/manage_map/map_parsing_bonus.c \
				${BONUSDIR}/manage_map/map_error_bonus.c \
				${BONUSDIR}/manage_map/map_path_bonus.c \
				${BONUSDIR}/manage_map/valid_path_bonus.c \
				${BONUSDIR}/sprites/images_init_bonus.c \
				${BONUSDIR}/sprites/enemy_jiggy_sprites.c \
				${BONUSDIR}/sprites/close_and_free_bonus.c \
				${BONUSDIR}/sprites/animate.c \
				${BONUSDIR}/sprites/animate_enemy.c \
				${BONUSDIR}/sprites/step_meter.c \
				${BONUSDIR}/action/move_bonus.c \
				${BONUSDIR}/action/exit_handle_bonus.c \
				${BONUSDIR}/action/enemy_move.c \

SRCS_BONUS 	= 	${BONUS_SRC}

################################################################################
#                                   Objects                                    #
################################################################################

OBJDIR 		= objs

OBJ    		= ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}

OBJS 		= ${BONUS_SRC:${BONUSDIR}/%.c=${OBJDIR}/%.o}

OBJS_BONUS 	= ${OBJS}

################################################################################
#                                   Colors                                     #
################################################################################

BLACK 	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE 	= \033[0;34m
PURPLE 	= \033[0;35m
CYAN 	= \033[0;36m

################################################################################
#                                    Rules                                     #
################################################################################

all: ${LIBFT_FILE} ${MINILBX_FILE} ${NAME}

${NAME} : ${OBJ} 
	@${CC} ${CFLAG} ${INCLUDES} ${OBJ} ${LFLAG} ${MLXFLAG} -o ${NAME}
	@echo "${YELLOW}✰✰✰ Alright, you can use ${NAME} ✰✰✰ :D"

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INC}
	@mkdir -p ${dir $@}
	@${CC} ${CFLAG} ${INCLUDES} -c $< -o $@
	@echo "${GREEN}***  SO_LONG: compilation success  ***"

bonus: ${LIBFT_FILE} ${MINILBX_FILE} ${NAME_BONUS}

${NAME_BONUS} : ${OBJS_BONUS}
	@${CC} ${CFLAG} ${INCLUDES_BONUS} ${OBJS_BONUS} ${LFLAG} ${MLXFLAG} -o ${NAME_BONUS}
	@echo "${YELLOW}✰✰✰ Bonus has been compiled ✰✰✰ :D"

${OBJDIR}/%.o: ${BONUSDIR}/%.c ${INCBONUS}
	@mkdir -p ${dir $@}
	@${CC} ${CFLAG} ${INCLUDES_BONUS} -c $< -o $@
	@echo "${GREEN}***  Bonus compilation success  ***"

${LIBFT_FILE} :
	@make -sC libft

${MINILBX_FILE} :
	@make -sC mlx-linux

clean: 
	@rm -rf ${OBJDIR}
	@echo "${PURPLE}► Cleaning done: ${OBJDIR} directory has been removed ◄"
	@make clean -C ${LIBFT_PATH}

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}
	@echo "${BLUE}► Fclean done: ${NAME} and ${NAME_BONUS} has been removed ◄"
	@make fclean -C ${LIBFT_PATH}

re: fclean all
	@echo "${CYAN}↻↻↻ Makefile has been re'd ↺↺↺ \o/"

.PHONY: all clean fclean re bonus
