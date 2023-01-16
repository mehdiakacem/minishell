/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:08:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/16 21:40:11 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_file(t_treenode *root, char *path, char **env)
{
	int	pid;

	if (access(path, X_OK) == 0 && access(path, F_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			g_exit_status = 1 * 256;
		}
		else if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);	
			if (execve(path, root->cmd, env) == -1)
				return (0);
		}
		wait(&g_exit_status);
		if (WIFSIGNALED(g_exit_status))
		{
			if (g_exit_status == SIGINT)
			{
				write(2, "\n", 1);
				g_exit_status = 130 * 256;
			}
			else if (g_exit_status == 3)
			{
				write(2, "Quit: 3\n", 9);
				g_exit_status = 131 * 256;
			}
		}
		return (1);
	}
	return (0);
}
