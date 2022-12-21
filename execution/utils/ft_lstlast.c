/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:18:29 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:19:06 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_lstlast(t_env *lst)
{
	t_env	*ptr;

	ptr = lst;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}