/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:50:21 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/02 22:10:36 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_pwd(int n_cmd, char **cmd, char **env)
{
    if (n_cmd > 1 && cmd[1][0] == '-')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]\n", cmd[1][1]);
        return ;
	}
	printf("%s\n", getenv("PWD"));
	return (env);
}