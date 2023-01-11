/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:50:21 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/09 16:43:30 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_pwd(int n_cmd, char **cmd, char **env)
{
	char	buff[1245];

	if (n_cmd > 1 && cmd[1][0] == '-' && cmd[1][1] != '\0')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", \
		cmd[1][1]);
		return (env);
	}
	getcwd(buff, 1245);
	printf("%s\n", buff);
	return (env);
}
