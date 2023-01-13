/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:35 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 09:59:14 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_create_new_env(char **old_env)
{
	char	**new_env;
	int		nbrof_env_var;

	nbrof_env_var = ft_count_env_var(old_env);
	new_env = malloc((nbrof_env_var + 1) * sizeof(char **));
	new_env = ft_populate(new_env, old_env);
	new_env = ft_shlvl_plus(new_env);
	if (ft_cmpin_env(new_env, "OLDPWD") == 1)
	{
		new_env = ft_remove_var(new_env, "OLDPWD");
	}
	new_env = ft_add_var("OLDPWD", new_env);
	return (new_env);
}