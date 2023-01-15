/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:03:11 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/15 22:03:27 by nmoussam         ###   ########.fr       */
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
		g_exit_status = 127 * 256;
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

void	ft_print(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
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
		ft_print(root->cmd[0]);
		g_exit_status = 127 * 256;
	}
}

void	ft_exec_cmd(t_treenode	*root, char **env)
{
	char	**str;

	str = path(root, env);
	if (path_exist(root->cmd[0]) == 1)
	{
		if (root->cmd[0][1] == '\0')
		{
			ft_dupin_close(root->stdin_fd, root->temp_fdin);
			ft_dupout_close(root->stdout_fd, root->temp_fdout);
			ft_printf("minishell: %s: is a directory\n", root->cmd[0]);
			g_exit_status = 126 * 256;
			return ;
		}
		else if (exec_file(root, root->cmd[0], env) == 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(root->cmd[0], 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			g_exit_status = 127 * 256;
			return ;
		}
		g_exit_status = 0;
	}
	else if (!str)
	{
		ft_printf("minishell: %s: No such file or directory\n", root->cmd[0]);
		g_exit_status = 127 * 256;
		return ;
	}
	else
		find_and_exec(root, str, env);
}
