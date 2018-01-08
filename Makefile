# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc -Wall -Werror -Wextra

SRC_NAME	= 	ft_isascii.c ft_isdigit.c ft_isspace.c ft_atoi.c ft_strlen.c ft_bzero.c\
				ft_strdup.c ft_memset.c ft_strnew.c\
				ft_printf.c ft_itoa_base.c ft_itoa_lli.c ft_unicode.c\
				ft_conv_sig_int.c ft_conv_unsig_int.c\
				ft_get_flags.c ft_get_type.c\
				ft_get_p.c ft_get_oux.c\
				ft_get_di.c ft_get_c.c ft_get_s.c\
				ft_print_width.c\
				ft_output_c_modul.c ft_output_s_modul.c ft_output_d_modul.c\
				ft_output_u_modul.c ft_output_ox_modul.c\
				ft_output_p_modul.c

OBJ 		= 	$(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

%.o: %.c
	@$(CC) -c -o $@ $< 
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ)
	@echo "Cleaning .o files"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re