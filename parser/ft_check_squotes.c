/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_squotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:47:05 by makacem           #+#    #+#             */
/*   Updated: 2022/12/16 17:00:49 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_count_squotes(char *str);

int	ft_check_squotes(t_token *token_list)
{
	int count;
	t_token *token;

	count = 0;
	token = token_list;
    token = token->next;
	while (token != NULL)
	{
		if (token->type == SQUOTE)
			count = count + ft_count_squotes(token->name);
		token = token->next;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int	ft_count_squotes(char *str)
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
