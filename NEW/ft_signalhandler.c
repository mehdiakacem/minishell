/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:52 by makacem           #+#    #+#             */
/*   Updated: 2023/01/06 13:23:01 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigstp(int sig)
{
	//ft_printf("exit\n");
	//exit(0);
}

void	ft_signalhandler(void)
{
	struct sigaction sa;

	sa.sa_handler = &handle_sigstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);

}