/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:59:14 by makacem           #+#    #+#             */
/*   Updated: 2023/01/07 13:27:50 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_redictionfor_input(t_token *tokne_list);
int		ft_redirect_input(t_token *redirec_token);
int		ft_append_input(t_token *redirec_token);

int	ft_fdin(t_token *token_list)
{
	int		fd_in;
	t_token	*redirection;
	t_token	*temp_token;

	fd_in = 0;
	redirection = token_list;
	while (redirection != NULL)
	{
		redirection = ft_redictionfor_input(token_list);
		if (redirection != NULL)
		{
			if (ft_strncmp(redirection->name, "<", 2) == 0)
				fd_in = ft_redirect_input(redirection);
			else if (ft_strncmp(redirection->name, "<<", 2) == 0)
				fd_in = ft_append_input(redirection);
		}
	}
	return (fd_in);
}

int	ft_redirect_input(t_token *redirec_token)
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
	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_printf("minishell: %s: No such file or directory\n", file_name);
		exit (0);
	}
	return (fd);
}

int	ft_append_input(t_token *redirec_token)
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

t_token	*ft_redictionfor_input(t_token *tokne_list)
{
	t_token	*token;

	token = tokne_list;
	while (token != NULL)
	{
		if (token->type == REDIRECTION
			&& (ft_strncmp(token->name, "<", 2) == 0 \
			|| ft_strncmp(token->name, "<<", 2) == 0))
			return (token);
		token = token->next;
	}
	return (NULL);
}
