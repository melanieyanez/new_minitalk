# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 11:49:16 by myanez-p          #+#    #+#              #
#    Updated: 2023/09/07 12:18:06 by melanieyane      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

# Dossiers

SRCDIR = srcs
OBJDIR = objs
HDRDIR = includes

# Fichiers

SRCS = $(shell find ${SRCDIR} -name '*.c')
OBJS = ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
HEADERS = ${HDRDIR}

# Compilation

GCC = GCC
CFLAGS = -Wall -Wextra -Werror

# Commandes

MKDIR = mkdir
RM = rm -Rf

# Règles

${OBJDIR}/%.o : ${SRCDIR}/%.c
		@${MKDIR} -p ${OBJDIR}
		@if [ ! -f libft/libft.a ]; then make -C libft; fi
		@echo "Compiling $< into ${@F}..."
		@${GCC} ${CFLAGS} -I ${HEADERS} -c $< -o $@
	

${NAME} : server client
	@echo "\nAll done!"

all : ${NAME}

server : ${OBJS}
	@echo "\nCompiling server executable..."
	@${GCC} ${CFLAGS} -I ${HEADERS} objs/utils.o objs/server.o -Llibft -lft -o server
	
client : ${OBJS}
	@echo "\nCompiling client executable..."
	@${GCC} ${CFLAGS} -I ${HEADERS} objs/utils.o objs/client.o -Llibft -lft -o client

# Nettoyage

clean : 
		@echo "Cleaning...\n"
		@make clean -C libft
		@${RM} ${OBJS}
		@${RM} ${OBJDIR}

fclean :	clean
			@echo "Full cleaning...\n"
			@make fclean -C libft
			@${RM} server
			@${RM} client

# Autres règles

re : fclean all

.PHONY: re fclean clean all