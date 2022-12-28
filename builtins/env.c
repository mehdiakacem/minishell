/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:28:34 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/28 15:59:36 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

// t_env   *get_env(char **env)
// {
//     int i;
//     t_env   *tmp;

//     tmp = NULL;
//     i = 0;
//     while(env[i])
//     {
//         ft_lstadd_back(&tmp, ft_lstnew(env[i]));
//         i++;
//     }
//     return(tmp);
// }

// void env(t_treenode **tree, char **en) 
// {
//     t_env   *tmp;
    
//     tmp = get_env(en);
//     if((*tree)->nb_cmd > 1)
//         printf("env: %s: No such file or directory\n", (*tree)->cmd[1]); //env -- # - () &
//     else if(ft_strcmp((*tree)->cmd[0], "env") == 0) 
//     {      
//         while(tmp)
//         {
//             if(tmp->content)
//             {
//                 printf("%s",tmp->var);
//                 printf("=");
//                 printf("%s\n", tmp->content);
//             }
//             tmp = tmp->next;
//         }
//     }
// }
