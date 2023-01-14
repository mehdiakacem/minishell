/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/14 13:54:05 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_type(t_token *token_list);
void	ft_print_token_content(t_token *token_list);

int exit_status = 0;
int val = 0;
int	main(int argc, char **argv, char **env)
{
	char		*line;
	int			error;
	t_token		*token_list;
	t_treenode	*root;

	argc = 0;
	argv = NULL;
	ft_signalhandler();
	env = ft_create_new_env(env);
	while (1)
	{
		line = readline("minishell$ ");
		if (!(line))
		{
			printf("minishell$ exit001\n");
			exit(1);
		}
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
			// ft_print_token_content(token_list);
			// ft_print_type(token_list);
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

