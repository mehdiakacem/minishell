/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:31 by makacem           #+#    #+#             */
/*   Updated: 2022/12/16 17:55:41 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_pars(t_token *token_list)
{
	t_token	*temp;
	
	// temp = token_list;
	// temp = temp->next;
	// while (temp != NULL)
	// {
	// 	if (temp->type == PIPE)
	// 		printf("PIPE ");
	// 	else if (temp->type == WORD)
	// 		printf("WORD ");
	// 	else if (temp->type == REDIRECTION)
	// 		printf("REDIRECTION ");
	// 	else if (temp->type == SPACE)
	// 		printf("SPACE ");
	// 	else if (temp->type == DQUOTE)
	// 		printf("DQUOTE ");
	// 	else if (temp->type == SQUOTE)
	// 		printf("SQUOTE ");
	// 	temp = temp->next;
	// }
	// printf("\n");

	if (ft_check_squotes(token_list) == 1)
		return (1);
	else if (ft_check_dquotes(token_list) == 1)
		return (1);
	else if (ft_check_pipes(token_list) == 1)
		return (1);
	return (0);
}

int	ft_pars_error(void)
{
	printf("pars error\n");
	return (1);
}
