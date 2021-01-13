# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 19:36:23 by jeldora           #+#    #+#              #
#    Updated: 2020/10/06 18:01:07 by jeldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				libft.a

FT_PRINTF_DIR = 	ft_printf/
GNL_DIR =			get_next_line/
ADDITIONAL_DIR = 	additional/

FLAGS = 			-g -c -Wall -Wextra -Werror -I. -D BUFFER_SIZE=32

LIBFT = 		ft_atoi.c ft_itoa.c ft_split.c ft_bzero.c \
				ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c

BONUS = 		ft_lstnew.c ft_lstiter.c \
				ft_lstlast.c ft_lstsize.c \
				ft_lstclear.c ft_lstdelone.c \
				ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstmap.c

FT_PRINTF =		$(FT_PRINTF_DIR)ft_basefree.c $(FT_PRINTF_DIR)ft_procent.c \
				$(FT_PRINTF_DIR)ft_printf.c $(FT_PRINTF_DIR)ft_fwidth.c \
				$(FT_PRINTF_DIR)ft_faccuracy.c $(FT_PRINTF_DIR)ft_ffind_len.c \
				$(FT_PRINTF_DIR)ft_ftype.c $(FT_PRINTF_DIR)ft_chartype.c \
				$(FT_PRINTF_DIR)ft_format.c $(FT_PRINTF_DIR)ft_strtype.c \
				$(FT_PRINTF_DIR)ft_inttype.c $(FT_PRINTF_DIR)ft_hexlowtype.c \
				$(FT_PRINTF_DIR)ft_hexuptype.c $(FT_PRINTF_DIR)ft_uinttype.c \
				$(FT_PRINTF_DIR)ft_pointertype.c

GNL =			$(GNL_DIR)get_next_line.c \
				$(GNL_DIR)get_next_line_exam.c
				#$(GNL_DIR)get_next_line_utils.c

ADDITIONAL = 	$(ADDITIONAL_DIR)ft_addchars.c $(ADDITIONAL_DIR)ft_clr_darray.c \
				$(ADDITIONAL_DIR)ft_height_darray.c $(ADDITIONAL_DIR)ft_darray.c \
				$(ADDITIONAL_DIR)ft_nbr_len.c $(ADDITIONAL_DIR)ft_itoa_hex_t.c \
				$(ADDITIONAL_DIR)ft_itoa_l.c $(ADDITIONAL_DIR)ft_itoa_hex.c \
				$(ADDITIONAL_DIR)ft_strmatch.c $(ADDITIONAL_DIR)ft_darray_dup.c \
				$(ADDITIONAL_DIR)ft_fexist.c $(ADDITIONAL_DIR)ft_cnt_srch.c \
				$(ADDITIONAL_DIR)ft_cnt_occur.c $(ADDITIONAL_DIR)ft_lst_to_darray.c \
				$(ADDITIONAL_DIR)ft_darray_split.c $(ADDITIONAL_DIR)ft_3array_len.c \
				$(ADDITIONAL_DIR)ft_3array_clr.c $(ADDITIONAL_DIR)ft_skip_spaces.c \
				$(ADDITIONAL_DIR)ft_lst_previous.c $(ADDITIONAL_DIR)ft_free.c

OBJ =			$(LIBFT:.c=.o) \
				$(BONUS:.c=.o) \
				$(GNL:.c=.o) \
				$(FT_PRINTF:.c=.o) \
				$(ADDITIONAL:.c=.o)

HEADERS =		$(FT_PRINTF_DIR)libftprintf.h $(GNL_DIR)get_next_line.h libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	ar rc $(NAME) $(OBJ) $(HEADERS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -g -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libft.a

re: fclean all

bonus: all
	@ echo "Bonuses compiled with mandatory part!"