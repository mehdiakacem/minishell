/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 14:10:53 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char	*line;
	int		error;

	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		error = ft_pars(ft_lex(line));
		if (error == 1)
			ft_pars_error();
		// system("leaks minishell");
		// exit(0);
	}
	return (0);
}
