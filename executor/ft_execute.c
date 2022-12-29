/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:15 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/29 17:54:16 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
#include <errno.h>
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
	{
		env = ft_export(n_cmd, cmd, env);
		// system("leaks minishell");
		// exit(0);
	}
	return (env);
}
void	execute_left(int *fd, t_treenode *left, char **env)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	ft_execute_rec(left, env);
	exit(0);
}
void	execute_right(int *fd, t_treenode *right, char **env)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	ft_execute_rec(right, env);
	exit(0);
}
void	ft_pipe(t_treenode *root, char **env)
{
	int	fd[2];
	int	pid;
	int val;

	val = pipe(fd);
	if (val == -1)
		return ;
	pid = fork();
	if (pid == 0)
		execute_right(fd, root->right, env);
	pid = fork();
	if (pid == 0)
		execute_left(fd, root->left, env);
	close(fd[0]);
	close(fd[1]);
}
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
	str = getenv("PATH");
	if(!str)
		return(NULL);
	split_path = ft_split(&str, ':');
	if(!split_path)
		return(NULL);
	return(split_path);
}

void	exec_file(t_treenode *root, char *path, char **env)
{
	int pid;

	if (access(path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
			printf("minishell: %s\n", strerror(errno));
		else if (pid == 0)
		{
			if (execve(path, root->cmd, env) == -1)
				printf("minishell: %s\n", strerror(errno));
		}
	}
}

void	find_and_exec(t_treenode *root, char **str)
{
	int i;
	char *tmp;
	char *path;

	tmp = ft_strjoin("/", tree->cmd[0]);
	if (!tmp)
		return ; // free
	i = 0;
	while(str[i])
	{
		path = ft_strjoin(str[i], tmp);
		if (!path)
			return ;
		exec_file(root, path, env);
		i++;
	}
}
void	ft_exec_cmd(t_treenode *root, char **env)
{
	char **str;
	str = path(root, env);
	if (path_exist(root->cmd[0]) == 1)
	{
		exec_file(root, str, env);
	}
	else
	{
		find_and_exec(root,str);
	}
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
		if (ft_check_builtin(*(root->cmd)) == 1)
			env = ft_exec_builtin(root->nb_cmd, root->cmd, env);
		else
			ft_exec_cmd(root, env);
		

		
	}
	ft_execute_rec(root->left, env);
	ft_execute_rec(root->right, env);
	return (env);
}

char	**ft_execute(t_treenode *root, char **env)
{
	env = ft_execute_rec(root, env);
	return (env);
}
