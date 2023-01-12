/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:56:49 by makacem           #+#    #+#             */
/*   Updated: 2023/01/12 10:00:16 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_populate(char **new_env, char **old_env)
{
	char	*new_array;
	char	**temp;

	temp = new_env;
	while (*old_env != '\0')
	{
		new_array = ft_strdup(*old_env);
		*temp = new_array;
		temp++;
		old_env++;
	}
	*temp = NULL;
	return (new_env);
}
