/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:12:35 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 22:19:48 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*new;
	int	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new = malloc(sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return (new);
	j = 0;
	while (j < len)
		new[j++] = s[start++];
	new[j] = '\0';
	return (new);
}