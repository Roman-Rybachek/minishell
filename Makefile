# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casteria <casteria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 06:23:58 by jeldora           #+#    #+#              #
#    Updated: 2020/10/07 15:34:31 by casteria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Если добавляем какой-то модуль, фукнции которого объединяет одна цель, то подключаем его так:
# Создаем переменную с путем
# MODUL_DIR = modul (это папка модуля)
# MODUL_SRCS =	$(MODUL_DIR)/func1.c \
#				$(MODUL_DIR)/func2.c \
#				$(MODUL_DIR)/func3.c
# Добавляем переменную $(MODUL_SRCS) в SRCS
# В папке с модулем создаем отдельный хедер с прототипами функций.
# В этот отдельный хедер подключаем ОБЯЗАТЕЛЬНО хедер "shared.h"
# Вставялем его в переменную HEADERS

NAME =					minishell

LIBFT_DIR = 			libft
LEXER_DIR =				lexer
PARSER_DIR =			parser
EXEC_DIR =				exec

FLAGS =					-Werror -Wall -Wextra -g -I. \
						-I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft \
						-I$(LEXER_DIR) \
						-I$(PARSER_DIR) \
						-I$(EXEC_DIR) \
						-o $(NAME)

LEXER_SRCS =			$(LEXER_DIR)/lexer.c \
						$(LEXER_DIR)/lexer_utils.c \
						$(LEXER_DIR)/lexer_env_utils.c \
						$(LEXER_DIR)/invalid_input.c \
						$(LEXER_DIR)/lexer_utils2.c


PARSER_SRCS =			$(PARSER_DIR)/parser_utils.c \
						$(PARSER_DIR)/parser_utils_2.c \
						$(PARSER_DIR)/parser_utils_3.c \
						$(PARSER_DIR)/parser.c

#EXEC_SRCS = 			exec.c pwd.c echo.c cd.c export.c unset.c env.c exit.c \
						exec_sys_func.c exec_utils.c
EXEC_SRCS =				$(EXEC_DIR)/exec.c \
						$(EXEC_DIR)/echo.c \
						$(EXEC_DIR)/pwd.c \
						$(EXEC_DIR)/export.c \
						$(EXEC_DIR)/env.c \
						$(EXEC_DIR)/exec_sys_func.c \
						$(EXEC_DIR)/exec_utils.c \
						$(EXEC_DIR)/parent_funcs.c \
						$(EXEC_DIR)/export_utils.c
#REL_EXEC_SRCS = 		$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS))
#EXEC_SRCS = 			$(EXEC_DIR)/exec.c $(EXEC_DIR)/pwd.c $(EXEC_DIR)/cd.c

SRCS =					minishell_utils.c \
						minishell_utils_2.c \
						signals.c \
						$(LEXER_SRCS) \
						$(PARSER_SRCS) \
						$(EXEC_SRCS)

LIBS =					$(LIBFT_DIR)/libft.a

HEADERS =				shared.h \
						$(LIBFT_DIR)/libft.h \
						$(LEXER_DIR)/lexer.h \
						$(PARSER_DIR)/parser.h \
						$(EXEC_DIR)/exec.h

all: build_libft $(NAME)

$(NAME): $(LIBS) minishell.c $(SRCS) $(HEADERS)
	gcc minishell.c $(SRCS) $(FLAGS)

t: $(LIBS) testing.c $(SRCS) $(HEADERS)
	gcc testing.c $(SRCS) $(FLAGS)

build_libft:
	cd $(LIBFT_DIR) && make; cd $(OLDPWD)

clean:
	cd $(LIBFT_DIR) && make fclean; cd $(OLDPWD)
	rm -rf minishell.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all
	