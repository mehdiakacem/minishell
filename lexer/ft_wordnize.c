/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:52:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/16 15:42:08 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_wordnize_dq(t_token *token)
{
	t_token	*temp_token;

	temp_token = token;
	while (temp_token != NULL)
	{
		if (temp_token->next != NULL && temp_token->type == DQUOTE)
		{
			temp_token = temp_token->next;
			while (temp_token->next != NULL && temp_token->type != DQUOTE)
			{
				if (temp_token->type != DOLLAR)
					temp_token->type = WORD;
				temp_token = temp_token->next;
			}
		}
		temp_token = temp_token->next;
	}
}

void	ft_wordnize_sq(t_token *token)
{
	t_token	*temp_token;
	char	*dollar;
	char	*var;
	t_token	*to_free;

	temp_token = token;
	while (temp_token != NULL)
	{
		if (temp_token->next != NULL && temp_token->type == SQUOTE)
		{
			temp_token = temp_token->next;
			while (temp_token->next != NULL && temp_token->type != SQUOTE)
			{
				if (temp_token->type != DOLLAR)
					temp_token->type = WORD;
				else if (temp_token->type == DOLLAR)
				{
					temp_token->type = WORD;
					if (temp_token->next->type == WORD)
					{
						to_free = temp_token->next;
						dollar = temp_token->name;
						var = temp_token->next->name;
						temp_token->name = ft_strjoin(dollar, var);
						free(dollar);
						free(var);
						temp_token->next = temp_token->next->next;
						free(to_free);
					}
				}
				temp_token = temp_token->next;
			}
		}
		temp_token = temp_token->next;
	}
}
