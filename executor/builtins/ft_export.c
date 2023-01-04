/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:39 by makacem           #+#    #+#             */
/*   Updated: 2023/01/03 19:00:53 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_export(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(*(cmd+1), "--") == 0
		|| ft_strncmp(*(cmd+1), "#", 1) == 0 || ft_strcmp(*(cmd+1), ";") == 0)))
	{
		ft_print_env(env);
		return (env);
	}
	else if (n_cmd > 1)
	{
		arg = cmd;
		arg++;
		while (*arg != NULL)
		{
			if (ft_isalpha(**arg) == 0)
				printf("minishell: export: `%s': not a valid identifier\n", *arg);
			else if (ft_search_env(env, *arg) == 0)
			{
				env = ft_add_var(*arg, env);
			}
			else if (ft_search_env(env, *arg) != 0
				&& ft_strchr(*arg, '=') != NULL
				&& ft_strchr(*arg, '+') != NULL)
			{
				printf("TEST3\n");	
			}
			else if (ft_search_env(env, *arg) != 0
				&& ft_strchr(*arg, '=') != NULL)
			{
				env = ft_remove_var(env, *arg);
				env = ft_add_var(*arg, env);
			}
			arg++;
		}
	}
	return (env);
}
