/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/22 13:35:18 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env *sort_env(t_env *head)
{    
    t_env *temp;
    t_env *temp_next;
    t_env *temp_head;

    temp_head = head;
    int  i;
    i = 0;
    while (temp_head != NULL && temp_head->next != NULL)
    {
        if (temp_head->var[0] > temp_head->next->var[0])
        {
            temp = temp_head;
            temp_head = temp_head->next;
            temp->next = temp_head->next;
            temp_head->next = temp;
        }
        // printf("%c   %c\n\n", temp_head->var[0], temp_head->next->var[0]);
        temp_head = temp_head->next;
    }
    return(head);
}


void export(int argc, char **argv, char **en) //nzid f env and tertib
{
    t_env   *temp;
    t_env   *tmp;
    
    temp = get_env(en);
    tmp = sort_env(temp);
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
    // t_env *cmd = get_env(en);
    export(argc, argv, en);
}