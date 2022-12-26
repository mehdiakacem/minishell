/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:39:53 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 15:47:02 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	int 	i;
	i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		// env(argc, argv, env);
		// builtins(argc, argv, env);
		
	}
	
}
