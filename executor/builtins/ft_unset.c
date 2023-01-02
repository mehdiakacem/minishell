/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:34:37 by makacem           #+#    #+#             */
/*   Updated: 2023/01/02 13:22:21 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// int		ft_cmpin_env(char	**env, char *var);
// char	**ft_remove_var(char	**env, char *var);

// char	**ft_unset(int n_cmd, char **cmd, char **env)
// {
// 	char	**arg;
// 	char	**temp_env;

	
// 	if (n_cmd == 1)
// 		return (env);
// 	else if (n_cmd > 1)
// 	{
// 		arg = cmd;
// 		cmd++;
// 		temp_env = env;
// 		while (*arg != NULL)
// 		{
// 			if (ft_cmpin_env(env, *arg) != NULL)
// 			{				
// 				env = ft_remove_var(*arg, env);
// 			}
// 			arg++;
// 		}
// 	}
// 	return (env);
// }

// char	**ft_remove_var(char	**env, char *var)
// {
	 

// 	return (env);
// }

//  int		ft_cmpin_env(char	**env, char *var)
// {
// 	char	**arr;
// 	int		var_len;

// 	arr = env;
// 	while (*arr != '\0')
// 	{
// 		if (ft_strcmp(*arr, var) == 0)
// 			return (1);
// 		arr++;
// 	}
// 	return (0);
// }