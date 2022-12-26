/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 21:46:29 by nmoussam         ###   ########.fr       */
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

int	find_ch(char *str, char ch)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return(0);
}



void export(t_treenode *tree, char **en) //nzid f env and tertib
{
    t_env   *temp;
    t_env   *tmp;
    int     val;
    int i;

    i = 1;
    val = 0;
    temp = get_env(en);
    tmp = sort_env(temp);
    if (tree->nb_cmd > 1 && tree->cmd[1][0] == '-' && tree->cmd[1][1] != '-' && tree->cmd[1][1] != '\0')
    {
        printf("minishell: export: -%c: invalid option\nexport: usage: export [-nf] [name[=value] ...] or export -p\n", tree->cmd[1][1]);
        return ;
    }
    if(tree->nb_cmd > 1 && ((tree->cmd[1][0] == '-' && tree->cmd[1][1] != '-') || ft_isdigit(tree->cmd[1][0]) == 1 ))
    {
        printf("minishell: export: '%s': not a valid identifier\n", tree->cmd[1]);
        return ;
    }
	while (i < tree->nb_cmd)
	{
			if (find_ch(tree->cmd[i], '=') == 1)
			{
				ft_lstadd_back(&tmp, ft_lstnew(tree->cmd[i]));
       			// while(tmp)
				// {
				// 	if(tmp->content)
				// 		printf("declare -x %s=\"%s\"\n", tmp->var, tmp->content);
				// 	tmp = tmp->next;
				// }
			}
			i++;
		}
        
    
     if(ft_strcmp(tree->cmd[0], "export") == 0 && (tree->cmd[1] == NULL || (tree->cmd[1][0] == '-' && tree->cmd[1][1] == '-') || tree->cmd[1][0] == '#'))
    {      
        while(tmp)
        {
            if(tmp->content)
            {
                val = 1;
                printf("declare -x %s=%s\n", tmp->var, tmp->content);
            }
            tmp = tmp->next;
        }
    }
    
}



// void	add_export(t_treenode *tree)
// {
// 	printf("declare -x ");
// 	ft_lstadd_back(tree->env, ft_lstnew())
// }