/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:01 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 17:23:55 by makacem          ###   ########.fr       */
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
	count = 0;
	while (token != NULL)
	{
		while (token->type != REDIRECTION && token->next != NULL)
		{
			if (token->type == PIPE)
				return(1);
			token = token->next;
		}
		
		token = token->next;
	}
	return (0);
}
