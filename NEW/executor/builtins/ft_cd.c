/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/08 16:08:52 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_jointo_old(char **env, char *arg);
char	**ft_search_val(char **env, char *var);

char	**ft_home(int n_cmd, char **cmd, char **env)
{
	char	*home;
	char	**pwd;
	char	**oldpwd;
	char	*tmp_pwd;

	home = ft_getenv(env, "HOME");
	tmp_pwd = ft_getenv(env, "PWD");
	if (!home)
	{
		printf("minishell: cd: HOME not set\n");
		return (env);
	}
	if (!tmp_pwd)
	{
		printf("error2\n");
		return (env);
	}
	if (chdir(home) == -1)
	{
		printf("minishell: cd: %s:\n", strerror(errno));
		return (env);
	}
	else
	{
		pwd = ft_search_val(env, "PWD=");
		oldpwd = ft_search_val(env, "OLDPWD=");
		*pwd = ft_strjoin("PWD=", home);
		*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
		printf("2\n");
	}
	return (env);
}

char	**ft_old_pwd(int n_cmd, char **cmd, char **env)
{
	char	**old_pwd;
	char	*tmp_pwd;

	tmp_pwd = ft_getenv(env, "PWD");
	if (!tmp_pwd)
	{
		printf("error3\n");
		return (env);
	}
	old_pwd = ft_search_val(env, "OLDPWD=");
	*old_pwd = ft_strjoin("OLDPWD=", tmp_pwd);
	return (env);
}

char	**ft_new_pwd(int n_cmd, char **cmd, char **env)
{
	char	*new_pwd;
	char	**pwd;

	new_pwd = getcwd(NULL, 0);
	pwd = ft_search_val(env, "PWD");
	*pwd = ft_strjoin("PWD=", new_pwd);
	return (env);
}

char	**ft_cd_point(char **cmd, char **env)
{
	printf("cd: error retrieving current directory: \
		getcwd: cannot access parent directories: No such file or directory");
	return (env);
}

char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*pwd;
	char	*oldpwd;

	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(cmd[1], "~") == 0 \
	|| ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0)))
	{
		env = ft_home(n_cmd, cmd, env);
		return (env);	
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			printf("minishell: cd: %s:\n", strerror(errno));
			return (env);
		}
		env = ft_old_pwd(n_cmd, cmd, env);
		env = ft_new_pwd(n_cmd, cmd, env);
	}
	if (ft_strcmp(cmd[1], ".") == 0 && !getcwd(NULL, 0))
	{
		env = ft_cd_point(cmd, env);
		return (env);
	}
	return (env);
}
