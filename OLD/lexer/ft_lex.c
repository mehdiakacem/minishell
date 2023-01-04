/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/28 18:59:35 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*ft_lex(char	*line)
{
	t_token	*token;
	t_token	*token_list;
	t_token	*temp;

	line = ft_strtrim(line, " ");
	token = ft_create_token_list(line);
	ft_tokenize(token);
	ft_wordnize(token);
	token_list = ft_grp_tokens(token);
	while (token != NULL)
	{
		free(token);
		token = token->next;
	}
	free(line);
	return (token_list);
}
