/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 22:17:42 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_utils2(char *line, t_token *token_list)
{
	ft_pars_error();
	free(line);
	ft_free_tokens(token_list);
}

void	ft_free1(char *line, t_token *token_list, t_treenode *root)
{
		free(line);
		ft_free_tokens(token_list);
		ft_free_tree(root);
}
int	main(int argc, char **argv, char **env)
{
	char		*line;
	int			error;
	t_token		*token_list;
	t_treenode	*root;

	argc = 0;
	argv = NULL;
	g_global.sig = 0;
	g_global.sig_cat = 0;
	env = ft_create_new_env(env);
	while (1)
	{
		handling_sig();
		line = readline("minishell$ ");
		g_global.exit_heredoc = 1;
		rl_event_hook = event;
		if (!(line))
			main_utils();
		if (ft_strlen(line) == 0)
		{
			free (line);
			continue ;
		}
		if (ft_strlen(line) != 0)
			add_history(line);
		token_list = ft_lex(line);
		error = ft_pars(token_list);
		if (error == 1)
			main_utils2(line, token_list);
		else
		{
			ft_empty_arg(token_list);
			ft_expand(token_list, env);
			root = ft_tree(token_list->next);
			env = ft_execute(root, env);
			ft_free1(line, token_list, root);
		}
	}
	ft_free_env(env);
	return (0);
}
