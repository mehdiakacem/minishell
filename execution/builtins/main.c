/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:39:53 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:26:50 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
