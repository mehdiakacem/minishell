/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/02 14:18:44 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_builtin(char	*cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}



char	**ft_exec_builtin(int n_cmd, char **cmd, char **env)
{
	if (ft_strcmp(*cmd, "env") == 0)
		env = ft_env(n_cmd, cmd, env);
	else if (ft_strcmp(*cmd, "export") == 0)
		env = ft_export(n_cmd, cmd, env);
	// else if (ft_strcmp(*cmd, "unset") == 0)
	// 	env = ft_unset(n_cmd, cmd, env);
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
			printf("minishell: : command not found\n");
		else if (ft_check_builtin(*(root->cmd)) == 1)
			env = ft_exec_builtin(root->nb_cmd, root->cmd, env);
		else
			ft_exec_cmd(root, env);	
		free(root->cmd);		
	}
	return (env);
}

char	**ft_execute(t_treenode *root, char **env)
{
	env = ft_execute_rec(root, env);
	return (env);
}
