/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:39 by makacem           #+#    #+#             */
/*   Updated: 2023/01/04 13:40:54 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_export(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(*(cmd+1), "--") == 0
		|| ft_strncmp(*(cmd+1), "#", 1) == 0 || ft_strcmp(*(cmd+1), ";") == 0)))
	{
		ft_print_env(env);
		return (env);
	}
	else if (n_cmd > 1)
	{
		arg = cmd;
		arg++;
		while (*arg != NULL)
		{
			if (ft_isalpha(**arg) == 0)
				printf("minishell: export: `%s': not a valid identifier\n", *arg);
			else if (ft_search_env(env, *arg) == 0)
			{
				env = ft_add_var(*arg, env);
			}
			else if (ft_search_env(env, *arg) != 0
				&& ft_strchr(*arg, '=') != NULL
				&& ft_strchr(*arg, '+') != NULL)
			{
				printf("TEST3\n");	
			}
			else if (ft_search_env(env, *arg) != 0
				&& ft_strchr(*arg, '=') != NULL)
			{
				env = ft_remove_var(env, *arg);
				env = ft_add_var(*arg, env);
			}
			arg++;
		}
	}
	return (env);
}






// int	find_ch(char *str, char ch)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '=')
// 			return (1);
// 		i++;
// 	}
// 	return(0);
// }



// void export(t_treenode *tree, char **en) //nzid f env and tertib
// {
//     t_env   *temp;
//     t_env   *tmp;
//     int     val;
//     int i;

//     i = 1;
//     val = 0;
//     temp = get_env(en);
//     tmp = sort_env(temp);
//     if (tree->nb_cmd > 1 && tree->cmd[1][0] == '-' && tree->cmd[1][1] != '-' && tree->cmd[1][1] != '\0')
//     {
//         printf("minishell: export: -%c: invalid option\nexport: usage: export [-nf] [name[=value] ...] or export -p\n", tree->cmd[1][1]);
//         return ;
//     }
//     if(tree->nb_cmd > 1 && ((tree->cmd[1][0] == '-' && tree->cmd[1][1] != '-') || ft_isdigit(tree->cmd[1][0]) == 1 ))
//     {
//         printf("minishell: export: '%s': not a valid identifier\n", tree->cmd[1]);
//         return ;
//     }
// 	while (i < tree->nb_cmd)
// 	{
// 			if (find_ch(tree->cmd[i], '=') == 1)
// 			{
// 				ft_lstadd_back(&tmp, ft_lstnew(tree->cmd[i]));
//        			while(tmp)
// 				{
// 					if(tmp->content)
// 						printf("declare -x %s=\"%s\"\n", tmp->var, tmp->content);
// 					tmp = tmp->next;
// 				}
// 			}
// 			i++;
// 		}
        
    
//      if(ft_strcmp(tree->cmd[0], "export") == 0 && (tree->cmd[1] == NULL || (tree->cmd[1][0] == '-' && tree->cmd[1][1] == '-') || tree->cmd[1][0] == '#' || tree->cmd[1][0] == ';'))
//     {      
//         while(tmp)
//         {
//             if(tmp->content)
//             {
//                 val = 1;
//                 printf("declare -x %s=%s\n", tmp->var, tmp->content);
//             }
//             tmp = tmp->next;
//         }
//     }
    
// }

