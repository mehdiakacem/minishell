/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:39 by makacem           #+#    #+#             */
/*   Updated: 2023/01/11 23:07:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		ft_pars_export(char *arg);
char	**ft_jointo_old(char **env, char *arg);

char	**ft_export(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1 || (n_cmd > 1 && (ft_strcmp(*(cmd + 1), "--") == 0 || \
	ft_strncmp(*(cmd + 1), "#", 1) == 0 || ft_strcmp(*(cmd + 1), ";") == 0)))
	{
		ft_print_env(env);
		exit_status = 0;
		return (env);
	}
	else if (n_cmd > 1)
	{
		arg = cmd;
		arg++;
		while (*arg != NULL)
		{
			if (ft_isalpha(**arg) == 0 || ft_pars_export(*arg) == 0)
				printf("minishell: export: `%s': not a valid identifier\n", \
				*arg);
			/* if (ft_isalpha(**arg) == 0)
			   {
					printf("minishell: export: `%s': not a valid identifier\n", *arg);
					exit_status = 1;
			   }
			   else if (ft_pars_export(*arg) == 0)
			   {
			   		printf("export: usage: export [-nf] [name[=value] ...] or export -p\n");
					exit_status = 2;
			   }
			
			*/
			else if (ft_search_env(env, *arg) == 0)
			{
				env = ft_add_var(*arg, env);
			}
			else if (ft_search_env(env, *arg) != 0
				&& ft_strchr(*arg, '=') != NULL
				&& ft_strchr(*arg, '+') != NULL)
			{
				env = ft_jointo_old(env, *arg);
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

char	**ft_jointo_old(char **env, char *arg)
{
	char	**old_val;
	char	**temp;

	temp = NULL;
	old_val = ft_search_val(env, arg);
	while (*arg != '\0' && *arg != '=')
		arg++;
	arg++;
	*temp = ft_strjoin(*old_val, arg);
	free(*old_val);
	*old_val = *temp;
	return (env);
}

int	ft_pars_export(char *arg)
{
	arg++;
	while (*arg != '\0' && *arg != '+' && *arg != '=')
	{
		if (ft_isalpha(*arg) == 0 && ft_isdigit(*arg) == 0)
			return (0);
		arg++;
		if (*arg == '+' && *(arg + 1) != '=')
			return (0);
	}
	return (1);
}

char	**ft_search_val(char	**env, char *var)
{
	char	**arr;
	int		var_len;
	char	*temp;

	arr = env;
	var_len = 0;
	temp = var;
	while (*temp != '\0' && *temp != '=' && *temp != '+')
	{
		var_len++;
		temp++;
	}
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, var, var_len) == 0)
			return (arr);
		arr++;
	}
	return (NULL);
}
