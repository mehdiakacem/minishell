/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:54:15 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/29 19:07:01 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_execute_rec(t_treenode *root, char **env)
{
	if (root == NULL)
	{
		return (env);
	}
	if (root->type == PIPE)
	{
		ft_pipe(root, env);
		return (env);
	}
	else if (root->type == CMD)
	{
		if (ft_check_builtin(*(root->cmd)) == 1)
			env = ft_exec_builtin(root->nb_cmd, root->cmd, env);
		else
			ft_exec_cmd(root, env);	
	}
	return (env);
}

char	**ft_execute(t_treenode *root, char **env)
{
	env = ft_execute_rec(root, env);
	return (env);
}
