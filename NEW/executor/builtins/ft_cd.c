/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/04 18:35:38 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	if (ft_strcmp(cmd[1], "~") == 0 || )
	
	
}