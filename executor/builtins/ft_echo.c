/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:49:15 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/03 14:17:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_alphabet(char *str, char alphabet)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] != alphabet)
			return (0);
		i++;
	}
	return (1);
}

char    **ft_echo(int n_cmd, char **cmd, char **env)
{
    int i;
    int val;

    val = 0;
    i = 1;
    if (cmd[i] == NULL)
        printf("\n");
    else
    {
        while (i < n_cmd && cmd[i][0] == '-' && cmd[i][1] == 'n' && check_alphabet(cmd[i], 'n') == 1)
        {
            val = 1;
            i++;
        }
        while (val == 0 && i < n_cmd)
        {
            printf("%s", cmd[i]);
            if (i != n_cmd - 1)
                printf(" ");
            i++;
        }
        if (val == 0)
            printf("\n");
        while (val == 1 && i < n_cmd && cmd[i] != NULL)
        {
            ft_printf("%s", cmd[i]);
            if (i != n_cmd - 1)
                ft_printf(" ");
            i++;
        }
    }
    return(env);
}
