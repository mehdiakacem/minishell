/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:02:58 by makacem           #+#    #+#             */
/*   Updated: 2023/01/07 13:26:15 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_treenode	*ft_tree(t_token *token_list)
{
	t_treenode	*root;

	if (ft_strlen(token_list->name) == 0)
		return (NULL);
	root = ft_pipe_links(token_list);
	root = ft_cmd_links(root, token_list);
	return (root);
}
