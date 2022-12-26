/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2022/12/26 18:34:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokens(t_token *token_list);

int	main(int argc, char **argv, char **en)
{
	char		*line;
	int			error;
	t_token		*token_list;
	t_treenode	*root;

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
			builtins(root, en);
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
