/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:41:08 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:50:42 by nmoussam         ###   ########.fr       */
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

typedef struct s_env
{
	char *var;
	char *content;
	struct s_env *next;

}			t_env; 

/*utils*/
void	ft_lstadd_back(t_env **alst, t_env *new);
t_env	*ft_lstnew(char *lst);
t_env	*ft_lstlast(t_env *lst);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, int len);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);

/* builtins */
void	builtins(int argc, char **argv, char **env);
void	echo(int argc, char **argv);
void	pwd(int argc, char **argv);
void	cd(int argc, char **argv);
void	unset(int argc, char **argv);
void 	export(int argc, char **argv, char **en) ;
void	exit_status(int argc, char **argv);
void 	env(int argc, char **argv, char **en);
t_env   *get_env(char **env);

#endif