/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:39:53 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/20 17:08:50 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtins(int argc, char **argv, char **env)
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
		env(argc, argv);
	else if (ft_strcmp(argv[1], "unset"))
		unset(argc, argv);
	else if (ft_strcmp(argv[1], "exit"))
		ft_exit(argc, argv);
	//else : another  command
}

int main(int argc, char **argv, char **env)
{
	char	*line;
	int 	i;
	i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		builtins(argc, argv, env);
		printf("%s", env[0]);
	}
	
}
