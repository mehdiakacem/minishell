/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:03:11 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/14 13:47:55 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	path_exist(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**path(t_treenode *root, char **env)
{
	char	*str;
	char	**split_path;

	root = NULL;
	str = ft_getenv(env, "PATH");
	if (!str)
	{
		exit_status = 127 * 256;
		return (NULL);
	}
	else
	{
		split_path = ft_split(str, ':');
		if (!split_path)
			return (NULL);
		return (split_path);
	}
}

int	exec_file(t_treenode *root, char *path, char **env)
{
	int	pid;

	if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
			printf("minishell: %s\n", strerror(errno));
		else if (pid == 0)
		{
			if (execve(path, root->cmd, env) == -1)
				return (0);
		}
		wait(&exit_status);
		return (1);
	}
	return (0);
}

void	find_and_exec(t_treenode *root, char **str, char **env)
{
	int		i;
	char	*tmp;
	char	*path;

	tmp = ft_strjoin("/", root->cmd[0]);
	if (!tmp)
		return ;// free
	i = 0;
	while (str[i])
	{
		path = ft_strjoin(str[i], tmp);
		if (exec_file(root, path, env) == 0)
			i++;
		else
			return ;
	}
	if (str[i] == NULL) 
	{
		ft_dupin_close(root->stdin_fd, root->temp_fdin);
		ft_dupout_close(root->stdout_fd, root->temp_fdout);
		printf("minishell: %s: command not found\n", root->cmd[0]);
		exit_status = 127 * 256;
	}
}

void	ft_exec_cmd(t_treenode	*root, char **env)
{
	char **str;

	str = path(root, env);
	if (!str)
	{
		printf("minishell: %s: No such file or directory\n", root->cmd[0]);
		exit_status = 127 * 256;
		return ;
	}
	if (path_exist(root->cmd[0]) == 1)
	{
		if (root->cmd[0][1] == '\0')
		{
			printf("minishell: %s: is a directory\n", root->cmd[0]);
			exit_status = 126 * 256;
			return ;
		}
		else if (exec_file(root, root->cmd[0], env) == 0)
		{
			printf("minishell: %s: %s\n", root->cmd[0], strerror(errno));
			exit_status = 127 * 256;
			return ;
		}
		exit_status = 0;
	}
	else
		find_and_exec(root, str, env);
}