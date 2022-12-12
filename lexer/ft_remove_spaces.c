/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:18:14 by makacem           #+#    #+#             */
/*   Updated: 2022/12/12 13:54:59 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_count_char(char *line);

char	**ft_remove_spaces(char *line)
{
	char	*new_line;
	char	**table;
	char	*c;

	line = ft_strtrim(line, " ");
	new_line = ft_calloc(ft_count_char(line) + 1, sizeof(char));
	c = new_line;
	while (*line != '\0')
	{ 
		while (ft_isprint(*line))
		{
			*c = *line;
			c++;
			line++;
		}
		if (*line == ' ')
		{
			*c = *line;
			line++;
			c++;
		}
		while (*line == ' ')
			line++;
	}
	table = ft_split(new_line, ' ');
	free(new_line);
	return (table);
}

int	ft_count_char(char *line)
{
	int count;

	count = 0;
	while (*line != '\0')
	{
		while (ft_isprint(*line))
		{
			count++;
			line++;
		}
		if (*line == ' ')
			count++;
		while (*line == ' ')
			line++;
	}
	return (count);
}
