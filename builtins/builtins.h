/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:32:20 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 20:30:19 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
typedef struct s_env
{
	char *var;
	char *content;
	struct s_env *next;

}			t_env; 

typedef struct t_treenode {
	int					type;
	char				**cmd;
	t_env				env;
	int					nb_cmd;
	int					stdin_fd;
	int					stdout_fd;
	struct t_treenode	*left;
	struct t_treenode	*right;
}	t_treenode;

int		check_alphabet(char *str, char alphabet);
void 	echo(t_treenode *tree);
t_env   *get_env(char **env);
void 	env(t_treenode *tree, char **en);
void	pwd(t_treenode *tree);
void    export(t_treenode *tree, char **en);
t_env   *sort_env(t_env *head);
void	builtins(t_treenode *tree, char **en);
void	ft_lstadd_back(t_env **alst, t_env *new_env);
t_env	*ft_lstlast(t_env *lst);
t_env	*ft_lstnew(char *lst);
int	    ft_strcmp(char *s1, char *s2);

#endif