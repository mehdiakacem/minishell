/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:17 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/17 22:07:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putchar22(int c)
{
	write(1, &c, 1);
	return (1);
}

int	event(void)
{
	return (0);
}

void	main_utils(void)
{
	char	*sr_cap;

	sr_cap = tgetstr("sr", NULL);
	tputs(sr_cap, 0, ft_putchar22);
	printf("minishell$ exit\n");
	exit(0);
}

int	ft_pars_error(void)
{
	ft_putstr_fd("minishell: syntax error\n", 2);
	g_global.exit_status = 258 * 256;
	return (1);
}
