/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:03:11 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/04 18:46:19 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int path_exist(char *path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			return(1);
		i++;
	}
	return(0);
}

char **path(t_treenode *root, char **env)
{
	char *str;
	char **split_path;
	str = ft_getenv(env, "PATH");
	if(!str)
		return(NULL);
	split_path = ft_split(str, ':');
	if(!split_path)
		return(NULL);
	return(split_path);
}

void	exec_file(t_treenode *root, char *path, char **env)
{
	int pid;

	if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
			printf("minishell: %s\n", strerror(errno));
		else if (pid == 0)
		{
			if (execve(path, root->cmd, env) == -1)
			{
				printf("minishell: %s: \n", strerror(errno));
				exit(127);
			}
		}
	}
	wait(NULL);
}

void	find_and_exec(t_treenode *root, char **str, char **env)
{
	int i;
	char *tmp;
	char *path;

	tmp = ft_strjoin("/", root->cmd[0]);
	if (!tmp)
		return ; // free
	i = 0;
	while(str[i])
	{
		path = ft_strjoin(str[i], tmp);
		if (!path)
		{
			printf("niullllll\n");
			return ;
		}
		exec_file(root, path, env);
		i++;
	}
	if (str[i] == NULL)
	{
		printf("minishell: %s: command not found\n", root->cmd[0]);

	}
}
void	ft_exec_cmd(t_treenode *root, char **env)
{
	char **str;
	str = path(root, env);
	if (path_exist(root->cmd[0]) == 1)
	{
		exec_file(root, root->cmd[0], env);
	}
	else
	{
		find_and_exec(root, str, env);
	}
}