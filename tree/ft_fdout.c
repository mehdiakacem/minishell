/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:02 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:44:09 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_redirect_output(t_token *redirec_token);
int		ft_append_output(t_token *redirec_token);
t_token	*ft_redictionfor_output(t_token *tokne_list);

int	ft_fdout(t_token *token_list)
{
	int		fd_out;
	t_token	*redirection;

	fd_out = 0;
	redirection = token_list;
	while (redirection != NULL)
	{
		redirection = ft_redictionfor_output(token_list);
		if (redirection != NULL)
		{
			if (ft_strncmp(redirection->name, ">", 2) == 0)
				fd_out = ft_redirect_output(redirection);
			else if (ft_strncmp(redirection->name, ">>", 2) == 0)
				fd_out = ft_append_output(redirection);
		}
	}
	return (fd_out);
}

int	ft_redirect_output(t_token *redirec_token)
{
	int		fd;
	char	*file_name;

	fd = 0;
	redirec_token->type = SPACEE;
	if (redirec_token->next->type == SPACEE)
	{
		file_name = redirec_token->next->next->name;
		redirec_token->next->next->type = SPACEE;
	}
	else
	{
		file_name = redirec_token->next->name;
		redirec_token->next->type = SPACEE;
	}
	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

int	ft_append_output(t_token *redirec_token)
{
	int		fd;
	char	*file_name;

	fd = 0;
	redirec_token->type = SPACEE;
	if (redirec_token->next->type == SPACEE)
	{
		file_name = redirec_token->next->next->name;
		redirec_token->next->next->type = SPACEE;
	}
	else
	{
		file_name = redirec_token->next->name;
		redirec_token->next->type = SPACEE;
	}
	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0777);
	return (fd);
}

t_token	*ft_redictionfor_output(t_token *tokne_list)
{
	t_token	*token;

	token = tokne_list;
	while (token != NULL)
	{
		if (token->type == REDIRECTION
			&& (ft_strncmp(token->name, ">", 2) == 0
			|| ft_strncmp(token->name, ">>", 2) == 0))
			return (token);
		token = token->next;
	}
	return (NULL);
}
