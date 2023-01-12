/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/11 23:01:56 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_env(int n_cmd, char **cmd, char **env)
{
	char	**arr;
	char	*var;

	cmd = NULL;
	if (n_cmd > 1)
	{
		ft_printf("env: usage: with no options or arguments\n");
		exit_status = 1;
		return (env);
	}
	arr = env;
	while (*arr != NULL)
	{
		if (ft_strchr(*arr, '=') != NULL)
		{
			var = *arr;
			while (*var != '=' && *var != '\0')
			{
				ft_putchar(*var);
				var++;
				if (*var == '+')
					var++;
			}
			if (*var != '\0')
			{
				ft_putchar('=');
				var++;
				ft_printf("%s", var);
			}
			ft_putchar('\n');
		}
		arr++;
	}
	exit_status = 0;
	return (env);
}
