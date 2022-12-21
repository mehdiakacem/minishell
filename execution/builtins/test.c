/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:30:02 by nmoussam          #+#    #+#             */
/*   Updated: 2022/12/21 23:30:13 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include<stdio.h>

// chdir function is declared
// inside this header
#include<unistd.h>
int main()
{
	char s[100];

	// printing current working directory
	printf("%s\n", getcwd(s, 100));

	// using the command
	chdir("..");

	// printing current working directory
	printf("%s\n", getcwd(s, 100));

	// after chdir is executed
	return 0;
}
