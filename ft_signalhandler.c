/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/14 11:50:26 by makacem          ###   ########.fr       */
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
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("^D\n");
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

void	ft_heredoc_signals(void)
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = &heredoc_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
