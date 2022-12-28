/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:02:58 by makacem           #+#    #+#             */
/*   Updated: 2022/12/28 19:00:47 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		printtree(t_treenode *root);

t_treenode	*ft_tree(t_token *token_list)
{
	t_treenode	*root;

	if (ft_strlen(token_list->name) == 0)
		return (NULL);
	root = ft_pipe_links(token_list);
	root = ft_cmd_links(root, token_list);
	//printtree(root);
	return (root);
}

void	printtabs(int nmbtabs)
{
	for	(int i=0; i < nmbtabs; i++)
	{
		printf("\t");
	}
}

void	printtree_rec(t_treenode *root, int level)
{
	char	**args;

	if (root == NULL)
	{
		printtabs(level);
		printf("--<empty>--\n");
		return ;
	}
	printtabs(level);
	if (root->type == PIPE)
		printf("PIPE\n");
	else if (root->type == CMD)
	{
		printf("CMD\n");
		args = root->cmd;
		while (*args != NULL)
		{
			printtabs(level);
			printf("%s\n", *args);
			args++;
		}
	}
	printtabs(level);
	printf("left\n");
	printtree_rec(root->left, level + 1);
	printtabs(level);
	printf("right\n");
	printtree_rec(root->right, level + 1);
	printtabs(level);
	printf("done\n");
}

void	printtree(t_treenode *root)
{
	printtree_rec(root, 0);
}
