# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 06:41:10 by ahooghe           #+#    #+#              #
#    Updated: 2023/11/18 14:33:12 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror -fPIC
DEBUG		:= -g
SRCS		:= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				ft_printf.c \
				ft_printf_hex.c \
				ft_printf_utils.c
OBJS		:= ${SRCS:.c=.o}
RM	    	:= rm -f

CYAN		:= \033[0;36m
RESET		:= \033[0m

%.o:		%.c compiling
			${CC} ${FLAGS} ${DEBUG} -c $< -o $@

${NAME}:	${OBJS}
			@echo ""
			@echo "${CYAN}Compiling ${NAME} ...${RESET}"
			ar rcs ${NAME} ${OBJS}
			@echo ""
			@echo "${CYAN}${NAME} Created${RESET}"

.PHONY:		all clean fclean re so

.INTERMEDIATE:	compiling

compiling:
			@echo ""
			@echo "${CYAN}Compiling Objects ...${RESET}"

all:		${NAME}

clean:
			@echo ""
			@echo "${CYAN}Deleting ${NAME} Objects ...${RESET}"
			${RM} *.o

fclean:		clean
			@echo ""
			@echo "${CYAN}Deleting ${NAME} Library ...${RESET}"
			${RM} ${NAME}

re:			fclean all

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
			gcc -nostartfiles -shared -o libft.so $(OBJS)
