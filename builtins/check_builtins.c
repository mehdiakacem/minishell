/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/27 16:14:33 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>

void	builtins(t_treenode *tree, char **en)
{
	int temp_fdout;

	if (tree->stdout_fd != 0)
	{
		temp_fdout = dup(STDOUT_FILENO);
		dup2(tree->stdout_fd, STDOUT_FILENO);
	}
	if (ft_strcmp(tree->cmd[0], "echo") == 0)
		echo(tree);
	// else if (ft_strcmp(tree->cmd[0], "pwd") == 0)
	// 	pwd(tree);
	// else if (ft_strcmp(tree->cmd[0], "env") == 0)
	// 	env(tree, en);
	// else if (ft_strcmp(tree->cmd[0], "cd"))
	// 	cd(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "export"))
	// 	export(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "unset"))
	// 	unset(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "exit"))
	// 	exit_status(argc, tree);
	//else : another command
	if (tree->stdout_fd != 0)
	{
		dup2(temp_fdout, STDOUT_FILENO);
		close(tree->stdout_fd);
	}
}
