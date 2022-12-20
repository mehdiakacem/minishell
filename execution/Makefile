# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 13:39:43 by nmoussam          #+#    #+#              #
#    Updated: 2022/12/20 16:46:43 by nmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INC  = ./include/minishell.h \
		./include/get_next_line.h
SRCS = 	srcs/main.c \
		srcs/echo.c \
		utils/ft_strcmp.c \
		srcs/pwd.c

		
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lreadline  -o $@ 

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all