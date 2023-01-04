/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/04 15:15:30 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_env(int n_cmd, char **cmd, char **env)
{
	char	**arr;
	char	*var;

	if (n_cmd > 1)
	{
		ft_printf("env: usage: with no options or arguments\n");
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
	return (env);
}
