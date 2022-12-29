/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:34:37 by makacem           #+#    #+#             */
/*   Updated: 2022/12/29 16:03:19 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_unset(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1)
		return (env);
	else if (n_cmd > 1)
	{
		arg = cmd;
		cmd++;
		while (*arg != NULL)
		{
			if (ft_search_env(env, *arg) == 1)
			{
				printf("arg :: %s\n", *arg);
				//env = ft_remove_var(*arg, env);
			}
			arg++;
		}
	}

	return (env);
}
 