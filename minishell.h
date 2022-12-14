/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:01 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 23:17:37 by nmoussam         ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>

# include "./lexer/lexer.h"
# include "./parser/parser.h"
# include "./expander/expander.h"
# define CMD 7
# define PIPE 1
int	exit_status;
int val;
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
int			ft_fdout(t_token *token_list);
int			ft_fdin(t_token *token_list);
int			ft_count_words(t_token *token);
int			ft_count_env_var(char	**env);
char		**ft_populate(char **new_env, char **old_env);
void		ft_free_env(char **env);
void		ft_signalhandler(void);
char		**ft_env(int n_cmd, char **cmd, char **env);
char		**ft_export(int n_cmd, char **cmd, char **env);
char		**ft_unset(int n_cmd, char **cmd, char **env);
char		**ft_echo(int n_cmd, char **cmd, char **env);
char		**ft_pwd(int n_cmd, char **cmd, char **env);
char		**ft_cd(int n_cmd, char **cmd, char **env);
int			check_alphabet(char *str, char alphabet);
char		**ft_add_var(char *var, char **env);
char		**ft_search_val(char	**env, char *var);
void		ft_print_env(char **env);
char		**ft_sort_env(char **env);
int			ft_search_env(char	**env, char *var);
char		**ft_remove_var(char	**env, char *var);
int			ft_search_env(char	**env, char *var);
char		**ft_home(char **env);
void		execute_left(int *fd, t_treenode *left, char **env);
void		execute_right(int *fd, t_treenode *right, char **env);
char		**ft_execute(t_treenode *root, char **env);
int			path_exist(char *path);
char		**path(t_treenode *root, char **env);
int			exec_file(t_treenode *root, char *path, char **env);
void		find_and_exec(t_treenode *root, char **str, char **env);
void		ft_exec_cmd(t_treenode *root, char **env);
char		**ft_execute_rec(t_treenode *root, char **env);
char		**execution_cmd(t_treenode *root, char **env);
void		ft_pipe(t_treenode *root, char **env);
int			ft_strcmp(char *s1, char *s2);
void		ft_to_lower(char *str);
char		**ft_shlvl_plus(char **env);
int			ft_count_env_var(char	**env);
char		*ft_getenv(char	**env, char *var);
void		ft_free_tokens(t_token *token_list);
char		**ft_create_new_env(char **old_env);
int			ft_cmpin_env(char	**env, char *var);
char		**ft_populate(char **new_env, char **old_env);
int			ft_dupin_open(int fd_stdin);
int			ft_dupout_open(int fd_stdout);
void    	ft_dupin_close(int fd_stdin, int temp_fdin);
void    	ft_dupout_close(int fd_stdout, int temp_fdout);
char    **ft_exit(int n_cmd, char **cmd, char **env);



#endif