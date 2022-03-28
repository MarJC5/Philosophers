# COLORS
GREEN	= \033[0;32m
RED 	= \033[0;31m
ORANGE	= \033[0;33m
CYAN	= \033[0;36m
RESET	= \033[0m

SRCS_DIR	= ./src/
SRCS_FILES	=  main.c
SRCS_FILES	+= mini_libft.c utils.c routine.c init.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR		= ./objs/
D_DIR		= ./debugs/
HEADS		= 

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
DEBUGS		:= ${patsubst %, ${D_DIR}%, ${OBJS_FILES}}

VALGRIND	= valgrind  --main-stacksize=167104768 --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=memcheckignore --gen-suppressions=yes
VALGRIND	= valgrind  --suppressions=memcheckignore --gen-suppressions=yes


NAME		= philo

CC			= cc
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

#Compile normal executable
${NAME}: ${O_DIR} ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "[$(ORANGE)$(NAME)$(RESET)] Creation *.o files & compilation : $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) is ready"

#Create objects directory
${O_DIR}:
	@${MKDIR} ${O_DIR}

#Compile normals objects
${O_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

#Compile and use valgrind
valgrind: ${D_DIR} ${DEBUGS}
	${RM} ${NAME}
	${CC} ${CFLAGS} -o ${NAME} ${DEBUGS} ${LIBS} -ggdb
	${VALGRIND} ./${NAME}


#Compile a debug executable with -g and fsanitize
debug: ${D_DIR} ${DEBUGS} 
	${CC} ${CFLAGS} -fsanitize=address -o ${NAME} ${DEBUGS} ${LIBS}

#Create debug directory
${D_DIR}:
	@${MKDIR} ${D_DIR}

#Compile debug objects
${D_DIR}%.o:${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -g ${HEADS} -o $@ -c $<

clean:
	@${RM} ${OBJS} ${OBJSB} ${DEBUGS}
	@${RM} -r ${O_DIR}
	@${RM} -r ${D_DIR}
	@echo "[$(ORANGE)$(NAME)$(RESET)] clean *.o files : $(GREEN)OK$(RESET)"

fclean:	clean
	@${RM} ${NAME}
	@${RM} -r ${NAME}.dSYM
	@echo "[$(ORANGE)$(NAME)$(RESET)] fclean: $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) has been clean up"

re: fclean all

.PHONY: all clean fclean re debug valgrind