/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 15:09:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env *sort_env(t_env *head)
{    
    char    *temp_var;
    char    *temp_content;
    t_env *temp_head;
    int  i;

    temp_head = head;
    while (temp_head != NULL)
    {
        temp_head = temp_head->next;
        i++;
    }
    while (i > 0)
    {
        temp_head = head;
        while (temp_head != NULL && temp_head->next != NULL)
        {
            if (temp_head->var[0] > temp_head->next->var[0])
            {
                temp_var = temp_head->var;
                temp_content = temp_head->content;
                temp_head->var = temp_head->next->var;
                temp_head->content = temp_head->next->content;
                temp_head->next->var = temp_var;
                temp_head->next->content = temp_content;
            }
            temp_head = temp_head->next;
        }
        i--;
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