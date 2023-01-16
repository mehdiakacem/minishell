/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:37:02 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/16 23:11:32 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_exit(int n_cmd, char **cmd, char **env)
{
	if (n_cmd == 1)
	{
		exit(0);
		g_exit_status = 0;
	}
	else if (n_cmd == 2 && ft_check_numeric(cmd[1]) == 1 && ft_strlen(cmd[1]) < 20)
	{
		printf("exit\n");
		g_exit_status = (ft_atoi(cmd[1]) % 256) * 256;
		exit(g_exit_status / 256);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		g_exit_status = 255 * 256;
		exit(g_exit_status / 256);
	}
	return (env);
}
