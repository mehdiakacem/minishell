/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:57:43 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 14:31:16 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv)
{
	DIR *dir = opendir(".");
	if (dir == NULL)
		return 1;
	
	struct  dirent* entity;
	entity = readdir(dir);
	while (entity != NULL)
	{
		printf("%s\n", entity->d_name);
		entity = readdir(dir);
	}
	closedir(dir);
	return 0;
}
