/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:01 by makacem           #+#    #+#             */
/*   Updated: 2023/01/04 13:23:44 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./lexer/lexer.h"
# include "./parser/parser.h"
# include "./expander/expander.h"


# define CMD 7
# define PIPE 1

typedef struct t_treenode {
	int					type;
	char				**cmd;
	int					nb_cmd;
	int					stdin_fd;
	int					stdout_fd;
	struct t_treenode	*left;
	struct t_treenode	*right;
}	t_treenode;


t_treenode	*ft_tree(t_token *token_list);
t_treenode	*ft_pipe_links(t_token *token_list);
int			ft_count_pipes(t_token *token_list);
t_treenode	*ft_cmd_links(t_treenode *root, t_token *token_list);
int			ft_count_words(t_token *token);
int			ft_count_env_var(char	**env);
char		**ft_populate(char **new_env, char **old_env);
char		**ft_execute(t_treenode *root, char **env);
int			ft_check_builtin(char *cmd);
char		**ft_exec_builtin(int n_cmd, char **cmd, char **env);
char		**ft_env(int n_cmd, char **cmd, char **env);
char		**ft_export(int n_cmd, char **cmd, char **env);
char		**ft_sort_env(char **env);
void		ft_print_env(char **env);
char		**ft_add_var(char *var, char **env);
int			ft_search_env(char	**env, char *var);
char		**ft_unset(int n_cmd, char **cmd, char **env);
char		**ft_echo(int n_cmd, char **cmd, char **env);
char		**ft_pwd(int n_cmd, char **cmd, char **env);
int			check_alphabet(char *str, char alphabet);
char		**ft_remove_var(char	**env, char *var);
int			ft_cmpin_env(char	**env, char *var);
void		ft_free_env(char **env);
int			ft_search_env(char	**env, char *var);
int			ft_check_builtin(char *cmd);
char		**ft_exec_builtin(int n_cmd, char **cmd, char **env);
int 		path_exist(char *path);
char 		**path(t_treenode *root, char **env);
void		exec_file(t_treenode *root, char *path, char **env);
void		find_and_exec(t_treenode *root, char **str, char **env);
void		ft_exec_cmd(t_treenode *root, char **env);
char		**ft_execute_rec(t_treenode *root, char **env);
char		**ft_execute(t_treenode *root, char **env);
void		execute_left(int *fd, t_treenode *left, char **env);
void		execute_right(int *fd, t_treenode *right, char **env);
void	execution_cmd(t_treenode *root, char **env);
void		ft_pipe(t_treenode *root, char **env);
int			ft_strcmp(char *s1, char *s2);
void    	ft_to_lower(char *str);

#endif