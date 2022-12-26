/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:21 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 17:49:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	pwd(t_treenode *tree)
{
    if (tree->nb_cmd > 1 && tree->cmd[1][0] == '-')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", tree->cmd[1][1]);
        return ;
	}
	printf("%s\n", getenv("PWD"));
}