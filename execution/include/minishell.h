/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:41:08 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:02 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

typedef struct s_arg{
	char **cmd;
	int argc;
    int type;
}	t_arg;

int	ft_strcmp(char *s1, char *s2);

/* builtins */
void	builtins(int argc, char **argv, char **env);
void	echo(int argc, char **argv);
void	pwd(int argc, char **argv);
void	cd(int argc, char **argv);
void	unset(int argc, char **argv);
void	export(int argc, char **argv);
void	ft_exit(int argc, char **argv);
void	env(int argc, char **argv);


#endif