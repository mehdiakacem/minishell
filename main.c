/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:38 by makacem           #+#    #+#             */
/*   Updated: 2023/01/17 22:02:26 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pars_error(void)
{
	ft_putstr_fd("minishell: syntax error\n", 2);
	g_exit_status = 258 * 256;
	return (1);
}

void	ft_free_tree(t_treenode *root);

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

void	ft_empty_arg(t_token *token_list);

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
		{
			char		*sr_cap;
            sr_cap = tgetstr("sr", NULL);
            tputs(sr_cap, 0, ft_putchar22);
	        printf("minishell$ exit\n");
            exit(0);
		}
		if (ft_strlen(line) == 0)
		{
			free (line);
			continue;
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
			ft_empty_arg(token_list);
			ft_expand(token_list, env);
			root = ft_tree(token_list->next);
			env = ft_execute(root, env);
			free(line);
			ft_free_tokens(token_list);
			ft_free_tree(root);
		}
	}
	ft_free_env(env);
	return (0);
}
