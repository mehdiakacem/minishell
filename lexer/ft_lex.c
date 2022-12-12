/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/12 17:40:48 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

 void	ft_tokenize(t_token *token);

t_token	ft_lex(char	*line)
{
	t_token	*token;
	char **words;
	t_token *temp;

	line = ft_strtrim(line, " ");
	token = ft_create_token_list(line);
	temp = token;
	ft_tokenize(token);
	while (temp != NULL)
	{
		printf("%d", temp->type);
		temp = temp->next;
	}
	printf("\n");
	return (*token);
} 
 
 void	ft_tokenize(t_token *token)
 {
	t_token	*temp;

	temp = token;
	while (temp != NULL)
	{
		if (temp->value == '|')
			temp->type = PIPE;
		else if (temp->value == '>' || temp->value == '<')
			temp->type = REDIRECTION;
		else if (temp->value == ' ')
			temp->type = SPACE;
		else if (ft_isprint(temp->value))
			temp->type = WORD;
		temp = temp->next;
	}
 }
 