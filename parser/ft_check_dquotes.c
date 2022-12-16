/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dquotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:51:17 by makacem           #+#    #+#             */
/*   Updated: 2022/12/15 17:53:01 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_count_dquotes(char *str);

int	ft_check_dquotes(t_token *token_list)
{
	int count;
	t_token *token;

	count = 0;
	token = token_list;
	while (token != NULL)
	{
		if (token->type == DQUOTE)
			count = count + ft_count_dquotes(token->name);
		token = token->next;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int	ft_count_dquotes(char *str)
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
