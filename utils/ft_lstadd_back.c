/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:17:29 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/26 17:46:20 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_env **alst, t_env *new_env)
{
	t_env	*last;

	if (!alst || !new_env)
		return ;
	if (!*alst)
		*alst = new_env;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new_env;
	}
}
