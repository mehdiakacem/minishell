/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:21:25 by makacem           #+#    #+#             */
/*   Updated: 2023/01/13 21:54:35 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	ft_expand(t_token *token_list, char **env)
{
	char	*var;
	char	*content;
	char	*allocated_cont;
	int		content_len;
	int		red;

	red = 0;
	while (token_list != NULL)
	{
		if (token_list->type == DOLLAR)
		{
			token_list->type = SPACEE;
			if (token_list->next == NULL || token_list->next->type == SPACEE)
				token_list->type = WORD;
			if (ft_strncmp(token_list->next->name, "?", 1) == 0)
			{
				free(token_list->next->name);
				token_list->next->name = ft_strjoin(ft_itoa(exit_status / 256), "");
			}
			else if (token_list->next->type == WORD)
			{
				var = token_list->next->name;
				content = ft_getenv(env, var);
				if (content == NULL)
				{
					token_list->next->type = 15;
					content = token_list->next->name;
				}
				content_len = ft_strlen(content) + 1;
				allocated_cont = malloc(content_len * sizeof(char));
				ft_strlcpy(allocated_cont, content, content_len);
				free(token_list->next->name);
				token_list->next->name = allocated_cont;
			}
		}
		else if (token_list->type == REDIRECTION && ft_strncmp(token_list->name, "<<", 2) == 0)
		{
			while(token_list->next != NULL)
			{
				if (token_list->type == DOLLAR && token_list->next->type == WORD)
				{
					token_list->type = SPACEE;
					var = token_list->next->name;
					token_list->next->name = ft_strjoin("$", var);
					free(var);
				}
				token_list = token_list->next;
			}
		}
		token_list = token_list->next;
	}
}
