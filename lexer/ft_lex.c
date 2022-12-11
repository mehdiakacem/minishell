/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:08:39 by makacem           #+#    #+#             */
/*   Updated: 2022/12/11 13:57:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#define PIPE '|'
void	ft_lex(char	*line)
{
	char **word;

	word = ft_split(line, ' ');
	while (*word != NULL)
	{
		printf("%s\n", *word);
		word++;
	}
}

int c;

c = PIPE;

printf()