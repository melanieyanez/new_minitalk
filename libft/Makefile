# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 13:08:59 by melanieyane       #+#    #+#              #
#    Updated: 2023/04/24 13:06:42 by myanez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Dossiers

SRCDIR = srcs
OBJDIR = objs/
HDRDIR = includes

# Fichiers

SRCS = $(shell find ${SRCDIR} -name '*.c')
OBJS = ${SRCS:${SRCDIR}%.c=${OBJDIR}%.o}
HEADERS = ${HDRDIR}
NAME = libft.a

# Compilation

GCC = GCC
CFLAGS = -Wall -Wextra -Werror

# Commandes

MKDIR = mkdir
RM = rm -Rf

# Sources

FTISDIR		= is
FTMEMDIR	= mem
FTPUTDIR	= put
FTTODIR		= to
FTSTRDIR	= str
FTPRINTDIR	= print
FTMATHDIR	= math
FTGNLDIR	= gnl

# Règles

${OBJDIR}%.o : ${SRCDIR}%.c
		@${MKDIR} -p ${OBJDIR}
		@${MKDIR} -p ${OBJDIR}${FTISDIR}
		@${MKDIR} -p ${OBJDIR}${FTMEMDIR}
		@${MKDIR} -p ${OBJDIR}${FTPUTDIR}
		@${MKDIR} -p ${OBJDIR}${FTTODIR}
		@${MKDIR} -p ${OBJDIR}${FTSTRDIR}
		@${MKDIR} -p ${OBJDIR}${FTPRINTDIR}
		@${MKDIR} -p ${OBJDIR}${FTMATHDIR}
		@${MKDIR} -p ${OBJDIR}${FTGNLDIR}
		@${GCC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME} : ${OBJS}
		@ar rc ${NAME} ${OBJS}

all : ${NAME}

# Nettoyage

clean : 
		@${RM} ${OBJS}
		@${RM} ${OBJDIR}

fclean :	clean
			@${RM} ${NAME}

# Autres règles

re : fclean all

.PHONY: re fclean clean all
