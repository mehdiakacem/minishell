/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 18:34:03 by nmoussam         ###   ########.fr       */
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


void export(t_treenode *tree, char **en) //nzid f env and tertib
{
    t_env   *temp;
    t_env   *tmp;

    temp = get_env(en);
    tmp = sort_env(temp);
    if(tree->nb_cmd > 1 && (ft_isdigit(tree->cmd[1][0]) == 1 || (tree->cmd[1][0] == '-' && tree->cmd[1][1] == '\0')))
        printf("minishell: export: '%s': not a valid identifier\n", tree->cmd[1]); //env -- # - () &
    if (tree->nb_cmd > 1 && tree->cmd[1][0] == '-' && tree->cmd[1][1] != '\0')
    {
        printf("minishell: export: -%c: invalid option\nexport: usage: export [-nf] [name[=value] ...] or export -p", tree->cmd[1][1]);
    }
    else if(ft_strcmp(tree->cmd[0], "export") == 0) 
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
