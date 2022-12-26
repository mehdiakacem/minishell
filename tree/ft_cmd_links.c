/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:26:43 by makacem           #+#    #+#             */
/*   Updated: 2022/12/26 17:20:40 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_treenode	*ft_create_cmd(t_token *token_list);
char		**ft_creat_args(t_token *token);
t_token		*ft_skip_tonextpipe(t_token *token_list);

t_treenode	*ft_cmd_links(t_treenode *root, t_token *token_list)
{
	int			nbr_of_pipes;
	t_treenode	*temp;
	t_treenode	*new_cmd;

	nbr_of_pipes = ft_count_pipes(token_list);
	if (root == NULL)
		root = ft_create_cmd(token_list);
	else if (root != NULL)
	{
		temp = root;
		while (nbr_of_pipes > 0)
		{
			new_cmd = ft_create_cmd(token_list);
			token_list = ft_skip_tonextpipe(token_list);
			temp->right = new_cmd;
			if (nbr_of_pipes == 1)
			{
				new_cmd = ft_create_cmd(token_list);
				temp->left = new_cmd;
			}
			temp = temp->left;
			nbr_of_pipes--;
		}
	}
	return (root);
}

t_token	*ft_skip_tonextpipe(t_token *token_list)
{
	while (token_list->type != PIPE)
		token_list = token_list->next;
	token_list = token_list->next;
	return (token_list);
}

t_token	*ft_rediction(t_token *tokne_list)
{
	t_token *token;

	token = tokne_list;
	while (token != NULL)
	{
		if (token->type == REDIRECTION)
			return (token);
		token = token->next;
	}
	return (NULL);
}

int	ft_redirect_output(t_token *redirec_token)
{
	int	fd;
	char	*file_name;

	fd = 0;
	redirec_token->type = SPACE;
	if (redirec_token->next->type == SPACE)
	{
		file_name = redirec_token->next->next->name;
		redirec_token->next->next->type = SPACE;
	}
	else
	{
		file_name = redirec_token->next->name;
		redirec_token->next->type = SPACE;
	}
	fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

int	ft_fdout(t_token *token_list)
{
	int	fd_out;
	t_token *redirection;

	fd_out = 0;
	redirection = ft_rediction(token_list);
	if (redirection != NULL)
	{
		if (ft_strncmp(redirection->name, ">", 2) == 0)
			fd_out = ft_redirect_output(redirection);
		else if (ft_strncmp(redirection->name, ">>", 2) == 0)
		{}
	}
	return (fd_out);
}

int	ft_count_cmds(char	**cmd)
{
	char	**temp;
	int		count;

	count = 0;
	temp = cmd;
	while (*temp != NULL)
	{
		count++;
		temp++;
	}
	return (count);
}

t_treenode	*ft_create_cmd(t_token *token_list)
{
	t_treenode	*root;

	root = malloc(sizeof(t_treenode));
	root->type = CMD;
	root->stdout_fd = ft_fdout(token_list);
	root->cmd = ft_creat_args(token_list);
	root->nb_cmd = ft_count_cmds(root->cmd);
	root->stdin_fd = 0;
	// printf("stdin %d\n", root->stdin_fd);
	// printf("stdout %d\n", root->stdout_fd);
	root->left = NULL;
	root->right = NULL;
	return (root);
}

char	**ft_creat_args(t_token *token)
{
	char		**args;
	char		**cmd;
	int			nbr_words;

	nbr_words = ft_count_words(token);
	cmd = malloc((nbr_words + 1) * sizeof(char **));
	args = cmd;
	while (token != NULL)
	{
		if (token->type == WORD || token->type == REDIRECTION)
		{
			*args = token->name;
			args++;
		}
		else if (token->type == PIPE)
		{
			*args = NULL;
			return (cmd);
		}
		token = token->next;
	}
	*args = NULL;
	return (cmd);
}

int	ft_count_words(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL)
	{
		if (token->type == WORD || token->type == REDIRECTION)
			count++;
		else if (token->type == PIPE)
			return (count);
		token = token->next;
	}
	return (count);
}
