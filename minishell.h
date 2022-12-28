/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:01 by makacem           #+#    #+#             */
/*   Updated: 2022/12/28 21:38:33 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./lexer/lexer.h"
# include "./parser/parser.h"
# include "./expander/expander.h"
# include "./builtins/builtins.h"

# define CMD 7
# define PIPE 1

t_treenode	*ft_tree(t_token *token_list);
t_treenode	*ft_pipe_links(t_token *token_list);
int			ft_count_pipes(t_token *token_list);
t_treenode	*ft_cmd_links(t_treenode *root, t_token *token_list);
int			ft_count_words(t_token *token);
int			ft_count_env_var(char	**env);
char		**ft_populate(char **new_env, char **old_env);
char        **ft_execute(t_treenode *root, char **env);
char		**ft_env(int n_cmd, char **cmd, char **env);
char		**ft_export(int n_cmd, char **cmd, char **env);
void		ft_free_env(char **env);

#endif