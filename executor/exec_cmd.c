/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:03:11 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/12 17:29:02 by makacem          ###   ########.fr       */
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
		exit_status = 127;
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
			{
				printf("minishell2: %s: \n", strerror(errno));
				return (0);
			}
		}
		wait(NULL);
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
		if (!path)
		{
			printf("niullllll\n");
			return ;
		}
		if (exec_file(root, path, env) == 0)
			i++;
		else
			return ;
	}
	if (str[i] == NULL) 
	{
		printf("minishell4: %s: command not found\n", root->cmd[0]);
	}
}

void	ft_exec_cmd(t_treenode	*root, char **env)
{
	char **str;

	str = path(root, env);
	if (!str)
	{
		printf("minishell: %s\n", strerror(errno));
		exit_status = 127;
		return ;
	}
	if (path_exist(root->cmd[0]) == 1)
	{
		if (exec_file(root, root->cmd[0], env) == 0)
		{
			printf("minishell: %s\n", strerror(errno));
			exit_status = 127;
			return ;
		}
		exit_status = 0;
	}
	else
		find_and_exec(root, str, env);
}