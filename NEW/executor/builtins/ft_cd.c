/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/07 13:29:47 by nmoussam         ###   ########.fr       */
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
	if (!home || !tmp_pwd)
	{
		printf("error2\n");
		return (env);
	}
	if (chdir(home) == -1)
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
	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(cmd[1], "~") == 0 \
	|| ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0)))
		env = ft_home(n_cmd, cmd, env);
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
	return (env);
}
