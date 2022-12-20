/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grp_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:34:05 by makacem           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:33 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_join_tokens(char **str, t_token *token);

t_token	*ft_grp_tokens(t_token *token)
{
	t_token	*list;
	t_token	*new_token;
	t_token	*temp;
	char	*str;

	list = (t_token *)malloc(sizeof(t_token));
	list->next = NULL;
	temp = list;
	while (token != NULL)
	{
		str = NULL;
		if (token->next == NULL || token->type != WORD || token->type != SPACE)
			str = ft_strjoin(&token->value, "");
		else if (token->next == NULL || token->type == WORD || token->type == 0)
			str = ft_strjoin(&token->value, "");
		token = ft_join_tokens(&str, token);
		new_token = (t_token *)malloc(sizeof(t_token));
		new_token->type = token->type;
		new_token->name = str;
		new_token->next = NULL;
		temp->next = new_token;
		temp = temp->next;
		token = token->next;
	}
	return (list);
}

t_token	*ft_join_tokens(char **str, t_token *token)
{
	char	*temp_str;

	while (token->next != NULL && ((token->type == WORD
				&& token->next->type == WORD) || (token->type == SPACE
				&& token->next->type == SPACE)))
	{
		if (*str == NULL)
		{
			temp_str = *str;
			*str = ft_strjoin(&token->value, "");
			free(temp_str);
		}
		temp_str = *str;
		*str = ft_strjoin(*str, &token->next->value);
		free(temp_str);
		token = token->next;
	}
	return (token);
}
