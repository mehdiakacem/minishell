/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:21:25 by makacem           #+#    #+#             */
/*   Updated: 2023/01/10 22:36:21 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	ft_expand(t_token *token_list, char **env)
{
	char	*var;
	char	*content;
	char	*allocated_cont;
	int		content_len;

	while (token_list != NULL)
	{
		if (token_list->type == DOLLAR)
		{
			if (token_list->next == NULL || token_list->next->type == SPACEE)
				token_list->type = WORD;
			else if (token_list->next->type == WORD)
			{
				var = token_list->next->name;
				content = ft_getenv(env, var);
				if (content == NULL)
					content = "";
				content_len = ft_strlen(content) + 1;
				allocated_cont = malloc(content_len * sizeof(char));
				ft_strlcpy(allocated_cont, content, content_len);
				free(token_list->next->name);
				token_list->next->name = allocated_cont;
			}
		}
		token_list = token_list->next;
	}
}
