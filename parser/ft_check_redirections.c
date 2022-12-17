/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:01 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 18:20:24 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int ft_check_redirections(t_token *token_list)
{
	t_token *token;
	int		count;

	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		if (token->type == REDIRECTION && token->next == NULL)
			return(1);
		token = token->next;
	}
	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		count = 0;
		while (token->type == REDIRECTION)
		{
			count++;
			if (count == 3)
				return (1);
			token = token->next;
		}
		token = token->next;
	}
	token = token_list;
	token = token->next;
	while (token != NULL)
	{
		if ((ft_strncmp(token->name, ">", 1) == 0 && ft_strncmp(token->next->name, "<", 1) == 0) ||
				(ft_strncmp(token->name, "<", 1) == 0 && ft_strncmp(token->next->name, ">", 1) == 0))
			return (1);
		token = token->next;
	}
	return (0);
}
