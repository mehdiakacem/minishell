/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:39 by makacem           #+#    #+#             */
/*   Updated: 2023/01/02 21:20:36 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_sort_env(char **env);
void	ft_print_env(char **env);
char	**ft_add_var(char *var, char **env);
int		ft_search_env(char	**env, char *var);

char	**ft_export(int n_cmd, char **cmd, char **env)
{
	char	**arg;

	if (n_cmd == 1)
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
			if (ft_search_env(env, *arg) == 0)
				env = ft_add_var(*arg, env);
			else if (ft_search_env(env, *arg) == 0 && ft_strchr(*arg, '=') != NULL)
			{
				
			}
			arg++;
		}
	}
	return (env);
}

int		ft_search_env(char	**env, char *var)
{
	char	**arr;
	int		var_len;
	char 	*temp;

	arr = env;
	var_len = 0;
	temp = var;
	while (*temp != '\0' && *temp != '=')
	{
		var_len++;
		temp++;
	}
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, var, var_len) == 0)
			return (1);
		arr++;
	}
	return (0);
}

char	**ft_add_var(char *var, char **env)
{
	char	**new_env;
	char	**last_place;
	char **temp;

	new_env = malloc((ft_count_env_var(env) + 2) * sizeof(char **));
	new_env = ft_populate(new_env, env);
	last_place = new_env;
	while (*last_place != NULL)
		last_place++;
	*last_place = ft_strdup(var);
	last_place++;
	*last_place = NULL;
	ft_free_env(env);
	return (new_env);
}

void	ft_print_env(char **env)
{
	char	**arr;
	char	**temp;
	char	*var;
	char	*content;

	arr = ft_sort_env(env);
	temp = arr;
	while (*temp != NULL)
	{
		ft_printf("declare -x ");
		var = *temp;
		while (*var != '=' && *var != '\0')
		{
			ft_putchar(*var);
			var++;
		}
		if (*var != '\0')
		{	
			ft_putchar('=');
			var++;
			ft_putchar('"');
			ft_printf("%s", var);
			ft_putchar('"');
		}
		ft_putchar('\n');
		temp++;
	}
	ft_free_env(arr);
}

char	**ft_sort_env(char **env)
{
	int nbrof_var;
	char	**arr;
	char	**temp_env;
	char	*temp;

	nbrof_var = ft_count_env_var(env);
	temp_env = malloc((nbrof_var + 1) * sizeof(char **));
	temp_env = ft_populate(temp_env, env);
	arr = temp_env;
	while (nbrof_var > 0)
	{
		arr = temp_env;
		while (*arr != NULL && *(arr + 1) != NULL)
		{
			if (ft_strcmp(*arr, *(arr+1)) > 0)
			{
				temp = *arr;
				*arr = *(arr+1);
				*(arr+1) = temp;
			}
			arr++;
		}
		nbrof_var--;
	}
	return (temp_env);
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

