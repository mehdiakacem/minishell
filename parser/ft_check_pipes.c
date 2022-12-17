/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:31:57 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 18:51:02 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_check_pipes(t_token *token_list)
{
	t_token *token;
	int		count;

	count = 0;
	token = token_list;
	while (token != NULL)
	{
		while ((token->type == DQUOTE || token->type == SQUOTE || token->type == WORD) && token->next != NULL)
		{
			count++;
			token = token->next;
		}
		if (token->type == PIPE)
		{
			if (count == 0)
				return (1);
			else if (token->next == NULL || token->next->type == PIPE)
				return (1);
			token = token->next;
			while (token->type == SPACE)
			{
				token = token->next;
				if (token->type == PIPE)
					return(1);
			}
		}
		token = token->next;
	}
	return (0);
}
