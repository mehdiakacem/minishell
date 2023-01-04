/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:56:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/02 21:43:49 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_left(int *fd, t_treenode *left, char **env)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	ft_execute_rec(left, env);
	exit(0);
}

void	execute_right(int *fd, t_treenode *right, char **env)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
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
