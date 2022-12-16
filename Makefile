# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:29:08 by makacem           #+#    #+#              #
#    Updated: 2022/12/16 17:32:52 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

FLAGS = -Wall -Werror -Wextra -lreadline 
\\ -fsanitize=address 
HEADER = minishell.h

SRC = main.c \
	lexer/ft_lex.c \
	lexer/ft_create_token_list.c \
	lexer/ft_tokenize.c \
	lexer/ft_grp_tokens.c \
	parser/ft_pars.c \
	parser/ft_check_squotes.c \
	parser/ft_check_dquotes.c \
	parser/ft_check_pipes.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) libft/libft.a

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re : fclean all