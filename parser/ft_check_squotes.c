/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_squotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:47:05 by makacem           #+#    #+#             */
/*   Updated: 2022/12/17 14:17:53 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
			count++;
		token = token->next;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}
