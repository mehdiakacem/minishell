/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2022/12/28 11:31:36 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokens(t_token *token_list);

int	ft_count_env_var(char	**env)
{
	int nbrof_env_var;

	nbrof_env_var = 0;
	while (*env != '\0')
	{
		nbrof_env_var++;
		env++;
	}
	return (nbrof_env_var);
}

char	**ft_populate(char **new_env, char **old_env)
{
	char	*new_array;
	char	**temp;

	temp = new_env;
	while (*old_env != '\0')
	{
		new_array = ft_strdup(*old_env);
		*temp = new_array;
		temp++;
		old_env++;
	}
	*temp = NULL;
	return (new_env); 
}

char	*ft_getenv(char	**env, char *var)
{
	char	*content;
	char	**arr;
	char	*shlvl;

	arr = env;
	content = NULL;
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, var, ft_strlen(var)) == 0)
		{
			content = ft_strchr(*arr, '=');
			content++;
			return (content);
		}
		arr++;
	}
	return (content);
}

void	ft_shlvl_plus(char **env)
{
	int shlvl_i;
	char	**arr;
	char	*shlvl;

	arr = env;
	while (*arr != '\0')
	{
		if (ft_strncmp(*arr, "SHLVL", 5) == 0)
		{
			shlvl = ft_strchr(*arr, '=');
			shlvl++;
			shlvl_i = ft_atoi(shlvl);
			shlvl_i++;
			*shlvl = *ft_itoa(shlvl_i);
		}
		arr++;
	}
}

char	**ft_create_new_env(char **old_env)
{
	char	**new_env;
	int		nbrof_env_var;

	nbrof_env_var = ft_count_env_var(old_env);
	new_env = malloc((nbrof_env_var + 1) * sizeof(char **));
	new_env = ft_populate(new_env, old_env);
	ft_shlvl_plus(new_env);

	return (new_env);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	int			error;
	t_token		*token_list;
	t_treenode	*root;

	env = ft_create_new_env(env);
	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		token_list = ft_lex(line);
		error = ft_pars(token_list);
		if (error == 1)
		{
			ft_pars_error();
			free(line);
			ft_free_tokens(token_list);
		}
		else
		{
			ft_expand(token_list->next);
			root = ft_tree(token_list->next);
			ft_execute(root);
			free(line);
			ft_free_tokens(token_list);
		}
		// system("leaks minishell");
		// exit(0);
	}
	return (0);
}

void	ft_free_tokens(t_token *token_list)
{
	free(token_list);
	token_list = token_list->next;
	while (token_list != NULL)
	{
		free(token_list->name);
		free(token_list);
		token_list = token_list->next;
	}
}
