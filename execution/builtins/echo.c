/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:19:44 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/23 18:23:48 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void echo(int argc, char **argv)
{
    int i;
    int val;

    char *str;
    val = 0;
    i = 2;
    str = "echo";
    
    if (strcmp(argv[1], str) == 0)
    {
        if (argv[i] == NULL)
            printf("\n");
        else
        {
            while (i < argc && argv[i][0] == '-' && check_alphabet(argv[i], 'n') == 1 && argv[i][0] != '\0')
            {
                val = 1;
                i++;
            }
            if (argv[i] == '\0')
                return ;
            if (val == 1)
            {
                while (i < argc)
                {
                    printf("%s", argv[i]); // to do (in case we print echo -n hello word "neeeed space. idea " print line until \0")
                    i++;
                }
            }
            else if (val == 0)
                printf("%s\n", argv[i]);
        }
    }
    
}
int main(int argc, char **argv)
{
    echo(argc, argv);
}