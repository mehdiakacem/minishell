/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:26:31 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:26:53 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtins(int argc, char **argv, char **en)
{
	if (ft_strcmp(argv[1], "echo"))
		echo(argc, argv);
	else if (ft_strcmp(argv[1], "pwd"))
		pwd(argc, argv);
	else if (ft_strcmp(argv[1], "cd"))
		cd(argc, argv);
	else if (ft_strcmp(argv[1], "export"))
		export(argc, argv);
	else if (ft_strcmp(argv[1], "env"))
		env(argc, argv, en);
	else if (ft_strcmp(argv[1], "unset"))
		unset(argc, argv);
	else if (ft_strcmp(argv[1], "exit"))
		exit_status(argc, argv);
	//else : another command
}
