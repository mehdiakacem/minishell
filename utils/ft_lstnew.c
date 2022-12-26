/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:16:01 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 21:35:04 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew(char *lst)
{
	t_env	*new;
	int len;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
    new->var = ft_substr(lst, 0, ft_strlen(lst) - ft_strlen(ft_strchr(lst, '=')));
	len = ft_strlen(lst) - ft_strlen(ft_strchr(lst, '='));
	new->content = ft_substr(lst, ft_strlen(lst) - ft_strlen(ft_strchr(lst, '=')) + 1, ft_strlen(lst+len+1));
	new->next = NULL;
	return (new);
}