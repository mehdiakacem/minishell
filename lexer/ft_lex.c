/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/13 17:47:18 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_group_tokens(t_token *token);

t_token	ft_lex(char	*line)
{
	t_token	*token;
	char **words;
	t_token *temp;
	t_token *new_token;

	line = ft_strtrim(line, " ");
	token = ft_create_token_list(line);
	temp = token;
	ft_tokenize(token);
	temp = ft_group_tokens(token);
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->type == SPACE)
			printf("SPACE ");
		else if (temp->type == PIPE)
			printf("PIPE ");
		else if (temp->type == WORD)
			printf("WORD ");
		else if (temp->type == REDIRECTION)
			printf("REDIRECTION ");
		temp = temp->next;
	}
	printf("\n");
	return (*token);
}

t_token	*ft_group_tokens(t_token *token)
{
	t_token *list;
	t_token	*new_token;
	t_token	*temp;
	char	*str;

	list = (t_token *)malloc(sizeof(t_token));
	list->next = NULL;
	temp = list;
	while (token != NULL)
	{
		str = NULL;
		if (token->next == NULL || token->type != token->next->type)
			str = ft_strjoin(&token->value, "");
		while (token->next != NULL && token->type == token->next->type)
		{
			if (str == NULL)
				str = ft_strjoin(&token->value, "");
			str = ft_strjoin(str, &token->next->value);
			token = token->next;
		}
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
