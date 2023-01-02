/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/29 16:12:36 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_sort_env(char **env);
void	ft_print_env(char **env);
char	**ft_add_var(char *var, char **env);
int		ft_search_env(char	**env, char *var);

char	**ft_export(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1)
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
			if (ft_search_env(env, *arg) == 0)
				env = ft_add_var(*arg, env);
			else if (ft_search_env(env, *arg) == 0 && ft_strchr(*arg, '=') != NULL)
			{
				
			}
			arg++;
		}
	}
	return (env);
}

int		ft_search_env(char	**env, char *var)
{
	char	**arr;
	int		var_len;
	char 	*temp;

	arr = env;
	var_len = 0;
	temp = var;
	while (*temp != '\0' && *temp != '=')
	{
		var_len++;
		temp++;
	}
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, var, var_len) == 0)
			return (1);
		arr++;
	}
	return (0);
}

char	**ft_add_var(char *var, char **env)
{
	char	**new_env;
	char	**last_place;
	char **temp;

	new_env = malloc((ft_count_env_var(env) + 2) * sizeof(char **));
	new_env = ft_populate(new_env, env);
	last_place = new_env;
	while (*last_place != NULL)
		last_place++;
	*last_place = ft_strdup(var);
	last_place++;
	*last_place = NULL;
	ft_free_env(env);
	return (new_env);
}

void	ft_print_env(char **env)
{
	char	**arr;
	char	**temp;
	char	*var;
	char	*content;

	arr = ft_sort_env(env);
	temp = arr;
	while (*temp != NULL)
	{
		ft_printf("declare -x ");
		var = *temp;
		while (*var != '=' && *var != '\0')
		{
			ft_putchar(*var);
			var++;
		}
		if (*var != '\0')
		{	
			ft_putchar('=');
			var++;
			ft_putchar('"');
			ft_printf("%s", var);
			ft_putchar('"');
		}
		ft_putchar('\n');
		temp++;
	}
	ft_free_env(arr);
}

char	**ft_sort_env(char **env)
{
	int nbrof_var;
	char	**arr;
	char	**temp_env;
	char	*temp;

	nbrof_var = ft_count_env_var(env);
	temp_env = malloc((nbrof_var + 1) * sizeof(char **));
	temp_env = ft_populate(temp_env, env);
	arr = temp_env;
	while (nbrof_var > 0)
	{
		arr = temp_env;
		while (*arr != NULL && *(arr + 1) != NULL)
		{
			if (ft_strcmp(*arr, *(arr+1)) > 0)
			{
				temp = *arr;
				*arr = *(arr+1);
				*(arr+1) = temp;
			}
			arr++;
		}
		nbrof_var--;
	}
	return (temp_env);
}
