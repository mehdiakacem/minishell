/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:08:41 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/17 21:42:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_signal(void)
{
	wait(&g_global.exit_status);
	if (WIFSIGNALED(g_global.exit_status))
	{
		if (g_global.exit_status == SIGINT)
		{
			g_global.sig_cat = 1;
			write(2, "\n", 1);
			g_global.exit_status = 130 * 256;
		}
		else if (g_global.exit_status == 3)
		{
			write(2, "Quit: 3\n", 9);
			g_global.exit_status = 131 * 256;
		}
	}
}

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
			g_global.exit_status = 1 * 256;
		}
		else if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			if (execve(path, root->cmd, env) == -1)
			{
				g_global.exit_status = 127 * 256;
				return (0);
			}
		}
		check_signal();
		return (1);
	}
	return (0);
}
