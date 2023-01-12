/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:50:21 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/11 22:49:46 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_pwd(int n_cmd, char **cmd, char **env)
{
	if (n_cmd > 1 && cmd[1][0] == '-' && cmd[1][1] != '\0')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", \
		cmd[1][1]);
		exit_status = 1;
		return (env);
	}
	printf("%s\n", getcwd(NULL, 0));
	exit_status = 0;
	return (env);
}
