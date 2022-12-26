/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 17:19:11 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtins(t_treenode *tree, char **en)
{
	if (ft_strcmp(tree->cmd[0], "echo"))
		echo(tree);
	// else if (ft_strcmp(tree->cmd[0], "pwd"))
	// 	pwd(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "cd"))
	// 	cd(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "export"))
	// 	export(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "env"))
	// 	env(argc, tree, en);
	// else if (ft_strcmp(tree->cmd[0], "unset"))
	// 	unset(argc, tree);
	// else if (ft_strcmp(tree->cmd[0], "exit"))
	// 	exit_status(argc, tree);
	//else : another command
}
