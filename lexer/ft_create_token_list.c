/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:17 by makacem           #+#    #+#             */
/*   Updated: 2022/12/13 14:51:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_create_token_list(char	*line)
{
	t_token *token;
	char	*c;
	t_token	*new_token;
	t_token	*temp;

	c = line;
	token = (t_token *)malloc(sizeof(t_token));
	token->value = *c;
	token->name = NULL;
	c++;
	token->next = NULL;
	temp = token;
	while (*c != '\0')
	{
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->value = *c;
		new_token->name = NULL;
		new_token->next = NULL;
		temp->next = new_token;
		temp = temp->next;
		c++;
	}
	return(token);
}
