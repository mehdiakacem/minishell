/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/03 19:11:40 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include "../minishell.h"

void	execution_cmd(t_treenode *root, char **env)
{
	char *tmp;

	tmp = ft_strdup(root->cmd[0]);
	ft_to_lower(tmp);
	if (ft_strcmp(tmp, "echo") == 0)
		env = ft_echo(root->nb_cmd, root->cmd, env);
	else if (ft_strcmp(tmp, "pwd") == 0)
		env = ft_pwd(root->nb_cmd, root->cmd, env);
	else if (ft_strcmp(root->cmd[0], "export") == 0)
		env = ft_export(root->nb_cmd, root->cmd, env);
	else if (ft_strcmp(tmp, "env") == 0)
		env = ft_env(root->nb_cmd, root->cmd, env);
	// else if (ft_strcmp(root->cmd[0], "cd") == 0)
	// 	env = ft_cd(root->nb_cmd, root->cmd, env);
	// else if (ft_strcmp(root->cmd[0], "unset") == 0)
	// 	env = ft_unset(root->nb_cmd, root->cmd, env);
	// else if (ft_strcmp(root->cmd[0], "exit") == 0)
	// 	env = ft_exit(root->nb_cmd, root->cmd, env);
	else
		ft_exec_cmd(root, env);
	free(tmp);
}
char	**ft_exec_builtin(int n_cmd, char **cmd, char **env)
{
	if (ft_strcmp(*cmd, "env") == 0)
		env = ft_env(n_cmd, cmd, env);
	else if (ft_strcmp(*cmd, "export") == 0)
		env = ft_export(n_cmd, cmd, env);
	// else if (ft_strcmp(*cmd, "unset") == 0)
	// 	env = ft_unset(n_cmd, cmd, env);
	else if (ft_strcmp(*cmd, "echo") == 0)
		env = ft_echo(n_cmd, cmd, env);
	return (env);
}


char	**ft_execute_rec(t_treenode *root, char **env)
{
	if (root == NULL)
	{
		return (env);
	}
	if (root->type == PIPE)
	{
		ft_pipe(root, env);
		return (env);
	}
	else if (root->type == CMD)
	{
		if (*(root->cmd) == NULL)
		{
			printf("minishell: : command not found\n");
			return (env);
		}
		execution_cmd(root, env);
		free(root->cmd);		
	}
	return (env);
}

char	**ft_execute(t_treenode *root, char **env)
{
	
	env = ft_execute_rec(root, env);
	return (env);
}