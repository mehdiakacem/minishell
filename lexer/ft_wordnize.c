/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:52:58 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 12:29:41 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_wordnize(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp != NULL)
	{
		if (temp->type == SQUOTE && temp->next != NULL)
		{
			temp = temp->next;
			while (temp->type != SQUOTE && temp->next != NULL)
			{
				temp->type = WORD;
				temp = temp->next;
			}
		}
		else if (temp->type == DQUOTE && temp->next != NULL)
		{
			temp = temp->next;
			while (temp->type != DQUOTE && temp->next != NULL)
			{
				temp->type = WORD;
				temp = temp->next;
			}
		}
		temp = temp->next;
	}
}