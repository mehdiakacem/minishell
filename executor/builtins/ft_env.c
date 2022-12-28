/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:06:52 by makacem           #+#    #+#             */
/*   Updated: 2022/12/28 21:53:58 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_env(int n_cmd, char **cmd, char **env)
{
	char	**arr;

	if (n_cmd > 1)
	{
		printf("env: usage: with no options or arguments\n");
		return (env);
	}
	arr = env;
	while (*arr != NULL)
	{
		if (ft_strchr(*arr, '=') != NULL)
			printf("%s\n", *arr);
		arr++;
	}
	return (env);
}
