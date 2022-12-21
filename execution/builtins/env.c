/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:28:34 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:43:30 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env   *get_env(char **env)
{
    int i;
    t_env   *tmp;

    tmp = NULL;
    i = 0;
    while(env[i])
    {
        ft_lstadd_back(&tmp, ft_lstnew(env[i]));
        i++;
    }
    return(tmp);
}

void env(int argc, char **argv, char **en) 
{
    t_env   *tmp;
    
    tmp = get_env(en);
    if(argc > 2)
        printf("env: %s: No such file or directory\n", argv[2]); //env -- # - () &
    else if(ft_strcmp(argv[1], "env") == 0) 
    {      
        while(tmp)
        {
            if(tmp->content)
            {
                printf("%s",tmp->var);
                printf("%s\n", tmp->content);
            }
            tmp = tmp->next;
        }
    }
}