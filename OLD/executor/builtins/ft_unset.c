/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:34:37 by makacem           #+#    #+#             */
/*   Updated: 2023/01/03 13:47:31 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_unset(int n_cmd, char **cmd, char **env)
{
	char	**arg;
	char	**temp_env;

	if (n_cmd == 1)
		return (env);
	else if (n_cmd > 1)
	{
		arg = cmd;
		arg++;
		temp_env = env;
		while (*arg != NULL)
		{
			if (ft_cmpin_env(env, *arg) == 1)
				env = ft_remove_var(env, *arg);
			arg++;
		}
	}
	return (env);
}

char	**ft_populate_unset(char **new_env, char **old_env, char *var)
{
	char	*new_array;
	char	**temp;
	char	*temp_arr;
	int		var_len;

	temp = new_env;
	while (*old_env != '\0')
	{
		temp_arr = var;
		var_len = 0;
		while (*temp_arr != '\0' && *temp_arr != '=')
		{
			var_len++;
			temp_arr++;
		}
		if (strncmp(*old_env, var, var_len) != 0)
		{
			new_array = ft_strdup(*old_env);
			*temp = new_array;
			temp++;
		}
		old_env++;
	}
	*temp = NULL;
	return (new_env);
}

char	**ft_remove_var(char	**env, char *var)
{
	char	**new_env;
	char	**last_place;
	char	**temp;

	new_env = malloc(ft_count_env_var(env) * sizeof(char **));
	new_env = ft_populate_unset(new_env, env, var);
	ft_free_env(env);
	return (new_env);
}

int	ft_cmpin_env(char	**env, char *var)
{
	char	**arr;
	char	*temp;
	int		var_len;

	arr = env;
	while (*arr != '\0')
	{
		temp = *arr;
		var_len = 0;
		while (*temp != '\0' && *temp != '=')
		{
			var_len++;
			temp++;
		}
		if (ft_strlen(var) == var_len)
		{
			if (ft_strncmp(*arr, var, var_len) == 0)
				return (1);
		}
		arr++;
	}
	return (0);
}