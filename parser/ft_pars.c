/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:31 by makacem           #+#    #+#             */
/*   Updated: 2022/12/18 14:31:48 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_print_type(t_token *token_list);
void	ft_print_token_content(t_token *token_list);

int	ft_pars(t_token *token_list)
{
	// ft_print_type(token_list);
	// ft_print_token_content(token_list);
	if (ft_check_dquotes(token_list) == 1)
		return (1);
	else if (ft_check_squotes(token_list) == 1)
		return (1);
	else if (ft_check_pipes(token_list) == 1)
		return (1);
	else if (ft_check_redirections(token_list) == 1)
		return (1);
	return (0);
}

int	ft_pars_error(void)
{
	printf("parse error\n");
	return (1);
}

void	ft_print_token_content(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	temp = temp->next;
	while (temp != NULL)
	{
		printf("'%s' ", temp->name);
		temp = temp->next;
	}
	printf("\n");
}

void	ft_print_type(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->type == PIPE)
			printf("PIPE ");
		else if (temp->type == WORD)
			printf("WORD ");
		else if (temp->type == REDIRECTION)
			printf("REDIRECTION ");
		else if (temp->type == SPACE)
			printf("SPACE ");
		else if (temp->type == DQUOTE)
			printf("DQUOTE ");
		else if (temp->type == SQUOTE)
			printf("SQUOTE ");
		temp = temp->next;
	}
	printf("\n");
}
