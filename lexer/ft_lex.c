/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/15 15:40:32 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_lex(char	*line)
{
	t_token	*token;
	t_token	*temp;
	t_token	*token_list;

	line = ft_strtrim(line, " ");
	free(line);
	token = ft_create_token_list(line);
	ft_tokenize(token);
	temp = ft_grp_tokens(token);
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			printf("PIPE ");
		else if (temp->type == WORD)
			printf("WORD ");
		else if (temp->type == REDIRECTION)
			printf("REDIRECTION ");
		else if (temp->type == SPACE)
			printf("SPACE ");
		else if (temp->type == DQUOTE)
			printf("DQUOTE ");
		else if (temp->type == SQUOTE)
			printf("SQUOTE ");
		temp = temp->next;
	}
	printf("\n");
	return (token_list);
}
