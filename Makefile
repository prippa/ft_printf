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
# FLAGS		=	-Wall -Werror -Wextra
COMPILER	=	gcc -g

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_LIB		=	./lib/
DIR_OBJ		= 	./obj/

#-------------------------- Header files ---------------------------------------
HEAD_FPF	=	ft_printf.h
HEAD_LIB	=	libft.h

#-------------------------- FPF Source files -----------------------------------
SRC_FPF		=	ft_printf.c fpf_cat_data.c fpf_parser.c fpf_trash.c\
				fpf_parser_get_type.c fpf_conversions.c fpf_unicode.c\
				ft_output_c_modul.c ft_output_s_modul.c ft_output_d_modul.c\
				ft_output_u_modul.c ft_output_ox_modul.c ft_output_p_modul.c\


#-------------------------- LIB Source files -----------------------------------
SRC_LIB		=	ft_strcpy.c ft_strlen.c ft_strdup.c ft_nbrlen.c\
				ft_isdigit.c ft_bzero.c ft_isascii.c ft_itoa.c\

INC_FPF 	= 	$(addprefix $(DIR_INC), $(HEAD_FPF))
INC_LIB 	= 	$(addprefix $(DIR_INC), $(HEAD_LIB))

OBJ 		= 	$(addprefix $(DIR_OBJ), $(SRC_LIB:.c=.o) $(SRC_FPF:.c=.o))
INC 		= 	$(addprefix -I, $(DIR_INC))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_FPF)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#lib
$(DIR_OBJ)%.o: $(DIR_LIB)%.c $(INC_LIB)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [obj files]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
