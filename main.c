/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/15 20:51:15 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


#include "minishell.h"
t_global	g_global;
int g_exit_status = 0;
int	event(void)
{
	return (0);
}
int ft_putchar22(int  c)
{
  write(1, &c, 1);
  return (1);     
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
	env = ft_create_new_env(env);
	while (1)
	{
		handling_sig();
		line = readline("minishell$ ");
		g_global.exit_heredoc = 1;
		rl_event_hook = event;
		if (!(line))
		{
			char		*sr_cap;
            sr_cap = tgetstr("sr", NULL);
            tputs(sr_cap, 0, ft_putchar22);
	        printf("minishell$ exit\n");
            exit(0);
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
