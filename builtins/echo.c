/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:19:44 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 18:30:06 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

void echo(t_treenode *tree)
{
    int i;
    int val;

    char *str;
    val = 0;
    i = 1;
    str = "echo";
    if (tree->cmd[0] != NULL && ft_strcmp(tree->cmd[0], str) == 0)
    {
        if (tree->cmd[i] == NULL)
            printf("\n");
        else
        {

            while (i < tree->nb_cmd && tree->cmd[i][0] == '-' && tree->cmd[i][1] == 'n' && check_alphabet(tree->cmd[i], 'n') == 1)
            {
                    val = 1;
                    i++;
                }
            while (val == 0 && i < tree->nb_cmd)
            {
                printf("%s", tree->cmd[i]);
                if (i != tree->nb_cmd - 1)
                    printf(" ");
                i++;
            }
            if (val == 0)
                printf("\n");
            while (val == 1 && i < tree->nb_cmd && tree->cmd[i] != NULL)
            {
                printf("%s", tree->cmd[i]);
                if (i != tree->nb_cmd - 1)
                    printf(" ");
                i++;
            }
        }
    }
    
}
