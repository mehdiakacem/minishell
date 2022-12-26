/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:18:29 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 15:11:26 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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