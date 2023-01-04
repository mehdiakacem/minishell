# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:29:08 by makacem           #+#    #+#              #
#    Updated: 2023/01/04 13:41:51 by nmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

FLAGS = -Wall -Werror -Wextra -lreadline 
\\ -fsanitize=address 
HEADER = minishell.h

SRC = main.c \
	lexer/ft_lex.c \
	lexer/ft_create_token_list.c \
	lexer/ft_tokenize.c \
	lexer/ft_wordnize.c \
	lexer/ft_grp_tokens.c \
	parser/ft_pars.c \
	parser/ft_check_squotes.c \
	parser/ft_check_dquotes.c \
	parser/ft_check_pipes.c \
	parser/ft_check_redirections.c \
	expander/ft_expand.c \
	tree/ft_tree.c \
	tree/ft_pipe_links.c \
	tree/ft_cmd_links.c \
	utils/ft_strcmp.c \
	utils/ft_lower.c \
	executor/ft_execute.c \
	executor/exec_cmd.c \
	executor/pipe.c \
	executor/builtins/ft_env.c \
	executor/builtins/ft_export.c \
	executor/builtins/ft_unset.c \
	executor/builtins/ft_echo.c \
	executor/builtins/ft_pwd.c \
	# executor/builtins/ft_unset.c \

	
	

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