/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:58:03 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void export(int argc, char **argv, char **en) //nzid f env and tertib
{
    t_env   *tmp;
    
    tmp = get_env(en);
    if(argc > 2 && (ft_isdigit(argv[2][0]) == 1 || (argv[2][0] == '-' && argv[2][1] == '\0')))
        printf("minishell: export: '%s': not a valid identifier\n", argv[2]); //env -- # - () &
    if (argc > 2 && argv[2][0] == '-' && argv[2][1] != '\0')
    {
        printf("minishell: export: -%c: invalid option\nexport: usage: export [-nf] [name[=value] ...] or export -p", argv[2][1]);
    }
    else if(ft_strcmp(argv[1], "export") == 0) 
    {      
        while(tmp)
        {
            if(tmp->content)
            {
                printf("declare -x ");
                printf("%s",tmp->var);
                printf("%s\n", tmp->content);
            }
            tmp = tmp->next;
        }
    }
}
int main(int argc, char **argv, char **en)
{
    export(argc, argv, en);
}