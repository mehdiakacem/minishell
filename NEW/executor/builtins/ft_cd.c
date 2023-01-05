/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/04 21:44:05 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
char	**ft_home(int n_cmd, char **cmd, char **env)
{
	
}
char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_getenv(env, "PWD");
	oldpwd = ft_getenv(env, "OLDPWD");
	if (!pwd || !oldpwd)
	{
		printf("error1\n");
		return (env);
	}
	if (ft_strcmp(cmd[1], "~") == 0 || ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0 || cmd[1] == NULL)
		env = ft_home(n_cmd, cmd, env);
	
	
}