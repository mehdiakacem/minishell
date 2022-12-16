/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:31:57 by makacem           #+#    #+#             */
/*   Updated: 2022/12/16 17:45:34 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_count_pipes(char *str);

int	ft_check_pipes(t_token *token_list)
{
	int count;
	t_token *token;

	count = 0;
	token = token_list;
	while (token != NULL)
	{
		if (token->type == SQUOTE && token->next != NULL)
		{
			token = token->next;
			while (token->type == SQUOTE && token->next != NULL)
				token = token->next;
		}
		token = token->next;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int	ft_count_pipes(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
