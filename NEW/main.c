/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/08 16:23:29 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokens(t_token *token_list);

int	ft_count_env_var(char	**env)
{
	int	nbrof_env_var;

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

char	**ft_shlvl_plus(char **env)
{
	int		shlvl_i;
	char	**old_val;
	char	*shlvl;
	char	**temp;

	shlvl = ft_getenv(env, "SHLVL");
	shlvl_i = ft_atoi(shlvl);
	shlvl_i++;
	shlvl = ft_itoa(shlvl_i);
	shlvl = ft_strjoin("SHLVL=", shlvl);
	old_val = ft_search_val(env, shlvl);
	free(*old_val);
	*old_val = shlvl;
	return (env);
}

int		ft_cmpin_env(char	**env, char *var);

char	**ft_create_new_env(char **old_env)
{
	char	**new_env;
	int		nbrof_env_var;

	nbrof_env_var = ft_count_env_var(old_env);
	new_env = malloc((nbrof_env_var + 1) * sizeof(char **));
	new_env = ft_populate(new_env, old_env);
	new_env = ft_shlvl_plus(new_env);
	if (ft_cmpin_env(new_env, "OLDPWD") == 1)
		new_env = ft_remove_var(new_env, "OLDPWD");
	return (new_env);
}

void	ft_free_env(char **env)
{
	char	**arr;

	arr = env;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(env);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	int			error;
	t_token		*token_list;
	t_treenode	*root;

	ft_signalhandler();
	env = ft_create_new_env(env);
	while (1)
	{
		line = readline("minishell$ ");
		if (ft_strlen(line) != 0)
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
			ft_expand(token_list->next, env);
			root = ft_tree(token_list->next);
			env = ft_execute(root, env);
			free(line);
			ft_free_tokens(token_list);
			free(root);
		}
	}
	ft_free_env(env);
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
