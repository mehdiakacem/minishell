/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/07 13:21:27 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	if (sig == SIGQUIT)
		return ;
	else if (sig == SIGSEGV)
	{
		ft_printf("exit\n");
		exit(0);
	}
	else if (sig == SIGINT)
	{
		return ;
	}
}

void	ft_signalhandler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
}
