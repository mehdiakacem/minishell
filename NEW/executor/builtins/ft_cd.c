/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/05 19:00:21 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
char	**ft_jointo_old(char **env, char *arg);
char	**ft_search_val(char	**env, char *var);

char	**ft_home(int n_cmd, char **cmd, char **env)
{
	char	*home;
	char 	**pwd;
	char 	**oldpwd;
	char 	*tmp_pwd;

	home = ft_getenv(env, "HOME");
	tmp_pwd = ft_getenv(env, "PWD");
	if (!home || !pwd)
	{
		printf("error2\n");
		return (env);
	}
	if(chdir(home) == -1)
        printf("minishell: cd: %s:\n", strerror(errno));
	else 
	{
		pwd = ft_search_val(env, "PWD=");
		oldpwd = ft_search_val(env, "OLDPWD=");
		*pwd = ft_strjoin("PWD=", home);
		*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
	}
	return (env);
}
char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_getenv(env, "PWD");
	oldpwd = ft_getenv(env, "OLDPWD");
	if (!pwd || !oldpwd)
	{
		printf("error1\n");
		return (env);
	}
	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(cmd[1], "~") == 0 || ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0 )))
	{
		env = ft_home(n_cmd, cmd, env);
	}
	// else if (n_cmd > 1 && (ft_strcmp(cmd[1], ".."))) 
	// cd /
	// cd .
	
		
	return (env);
	
	
}