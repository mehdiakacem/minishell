/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 16:57:00 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_grp_two_words(t_token *token);

t_token	*ft_lex(char	*line)
{
	t_token	*token;
	t_token	*token_list;

	line = ft_strtrim(line, " ");
	token = ft_create_token_list(line);
	ft_tokenize(token);
	ft_wordnize(token);
	token_list = ft_grp_tokens(token);
	ft_grp_two_words(token_list);
	while (token != NULL)
	{
		free(token);
		token = token->next;
	}
	free(line);
	return (token_list);
}

void	ft_grp_two_words(t_token *token)
{
	char	*new_word;

	new_word = NULL;
	while (token != NULL && token->next !=NULL && token->next->next != NULL)
	{
		if ((token->type == WORD && token->next->type == DQUOTE && token->next->next->type == WORD))
		{
			new_word = ft_strjoin(token->name, token->next->next->name);
			free(token->name);
			token->name = new_word;
			token->next->next->type = SPACEE;
		}
		token = token->next;
	}
}
