/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:21 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/20 17:00:42 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd(int argc, char **argv)
{
    if (argc > 2 && argv[2][0] == '-')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]", argv[2][1]);
        return ;
	}
	printf("%s", getenv("PWD"));
}