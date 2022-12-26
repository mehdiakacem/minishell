/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 18:34:31 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtins(t_treenode *tree, char **en)
{
	if (ft_strcmp(tree->cmd[0], "echo") == 0)
		echo(tree);
	else if (ft_strcmp(tree->cmd[0], "pwd") == 0)
		pwd(tree);
	else if (ft_strcmp(tree->cmd[0], "env") == 0)
		env(tree, en);
	else if (ft_strcmp(tree->cmd[0], "export") == 0)
		export(tree, en);
	// else if (ft_strcmp(tree->cmd[0], "cd") == 0)
	// 	cd(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "unset") == 0)
	// 	unset(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "exit") == 0)
	// 	exit_status(argc, tree);
	//else : another command
}
