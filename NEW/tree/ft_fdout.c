/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:54:02 by makacem           #+#    #+#             */
/*   Updated: 2023/01/07 13:27:02 by nmoussam         ###   ########.fr       */
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
	t_token	*temp_token;

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
	redirec_token->type = SPACE;
	if (redirec_token->next->type == SPACE)
	{
		file_name = redirec_token->next->next->name;
		redirec_token->next->next->type = SPACE;
	}
	else
	{
		file_name = redirec_token->next->name;
		redirec_token->next->type = SPACE;
	}
	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

int	ft_append_output(t_token *redirec_token)
{
	int		fd;
	char	*file_name;

	fd = 0;
	redirec_token->type = SPACE;
	if (redirec_token->next->type == SPACE)
	{
		file_name = redirec_token->next->next->name;
		redirec_token->next->next->type = SPACE;
	}
	else
	{
		file_name = redirec_token->next->name;
		redirec_token->next->type = SPACE;
	}
	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (fd);
}

t_token	*ft_redictionfor_output(t_token *tokne_list)
{
	t_token	*token;

	token = tokne_list;
	while (token != NULL)
	{
		if (token->type == REDIRECTION
			&& (ft_strncmp(token->name, ">", 2) == 0 \
			|| ft_strncmp(token->name, ">>", 2) == 0))
			return (token);
		token = token->next;
	}
	return (NULL);
}
