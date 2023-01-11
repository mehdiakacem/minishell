/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/11 12:16:47 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGQUIT)
		return ;
	else if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);2
		rl_redisplay();
	}
}

void	ft_signalhandler(void)
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
}
