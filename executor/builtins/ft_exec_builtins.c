/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:05:47 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/31 12:02:32 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

char	**ft_exec_builtin(int n_cmd, char **cmd, char **env)
{
	if (ft_strcmp(*cmd, "env") == 0)
		env = ft_env(n_cmd, cmd, env);
	else if (ft_strcmp(*cmd, "export") == 0)
	{
		env = ft_export(n_cmd, cmd, env);
	}
	return (env);
}
