/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/28 14:45:56 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>

void	builtins(t_treenode *tree)
{
	int temp_fdout;

	if (tree->stdout_fd != 0)
	{
		temp_fdout = dup(STDOUT_FILENO);
		dup2(tree->stdout_fd, STDOUT_FILENO);
	}
	if (ft_strcmp(tree->cmd[0], "echo") == 0)
		echo(tree);
	else if (ft_strcmp(tree->cmd[0], "pwd") == 0)
		pwd(tree);
	// else if (ft_strcmp(tree->cmd[0], "env") == 0)
	// 	env(&tree);
	// else if (ft_strcmp(tree->cmd[0], "export") == 0)
	// 	export(tree, en);
	// else if (ft_strcmp(tree->cmd[0], "cd") == 0)
	// 	cd(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "unset") == 0)
	// 	unset(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "exit") == 0)
	// 	exit_status(argc, tree);
	//else : another command
	if (tree->stdout_fd != 0)
	{
		dup2(temp_fdout, STDOUT_FILENO);
		close(tree->stdout_fd);
	}
}


