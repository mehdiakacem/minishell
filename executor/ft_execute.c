/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:45:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 23:17:10 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**execution_cmd(t_treenode *root, char **env)
{
	char	*tmp;
	int		temp_fdin;
	int		temp_fdout;

	temp_fdin = ft_dupin_open(root->stdin_fd);
	temp_fdout = ft_dupout_open(root->stdout_fd);
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
	else if (ft_strcmp(root->cmd[0], "cd") == 0)
		env = ft_cd(root->nb_cmd, root->cmd, env);
	else if (ft_strcmp(root->cmd[0], "unset") == 0)
		env = ft_unset(root->nb_cmd, root->cmd, env);
	else if (ft_strcmp(root->cmd[0], "exit") == 0)
		env = ft_exit(root->nb_cmd, root->cmd, env);
	else
		ft_exec_cmd(root, env);
	free(tmp);
	ft_dupin_close(root->stdin_fd, temp_fdin);
	ft_dupout_close(root->stdout_fd, temp_fdout);
	return (env);
}

char	**ft_execute_rec(t_treenode *root, char **env)
{
	if (root == NULL)
		return (env);
	if (root->type == PIPE)
	{
		ft_pipe(root, env);
		return (env);
	}
	else if (root->type == CMD)
	{
		if (*(root->cmd) == NULL && root->stdin_fd == 0 && root->stdout_fd == 0)
		{
			printf("minishell: : command not found\n");
			return (env);
		}
		if (*(root->cmd) != NULL)
			env = execution_cmd(root, env);
		free(root->cmd);
	}
	return (env);
}

char	**ft_execute(t_treenode *root, char **env)
{
	env = ft_execute_rec(root, env);
	return (env);
}
