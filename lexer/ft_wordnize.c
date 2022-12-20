/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:52:58 by makacem           #+#    #+#             */
/*   Updated: 2022/12/20 14:19:44 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_wordnize(t_token *token)
{
	while (token != NULL)
	{
		if (token->type == SQUOTE && token->next != NULL)
		{
			token = token->next;
			while (token->type != SQUOTE && token->next != NULL)
			{
				token->type = WORD;
				token = token->next;
			}
		}
		else if (token->type == DQUOTE && token->next != NULL)
		{
			token = token->next;
			while (token->type != DQUOTE && token->type != DOLLAR
				&& token->next != NULL)
			{
				token->type = WORD;
				token = token->next;
			}
		}
		token = token->next;
	}
}
