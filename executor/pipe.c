/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:56:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/15 21:42:53 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execute_utils(int *fd, t_treenode *root, char **env, int id)
{
	if (id == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		ft_execute_rec(root->right, env);
		exit(127);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		ft_execute_rec(root->left, env);
		exit(0);
	}
}

void	ft_pipe(t_treenode *root, char **env)
{
	int	fd[2];
	int	pid;
	int	val;

	val = pipe(fd);
	if (val == -1)
		return ;
	pid = fork();
	if (pid == 0)
		ft_execute_utils(fd, root, env, 0);
	pid = fork();
	if (pid == 0)
		ft_execute_utils(fd, root, env, 1);
	close(fd[0]);
	close(fd[1]);
	wait(&g_exit_status);
	wait(&g_exit_status);
}
