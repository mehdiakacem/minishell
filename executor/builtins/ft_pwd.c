/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:50:21 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/02 19:50:37 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd(t_treenode *tree)
{
    if (tree->nb_cmd > 1 && tree->cmd[1][0] == '-')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", tree->cmd[1][1]);
        return ;
	}
	printf("%s\n", getenv("PWD"));
}