/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/15 18:42:10 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_home(char **env)
{
	char	*home;
	char	**pwd;
	char	**oldpwd;
	char	*tmp_pwd;
	char	*new_pwd;

	home = ft_getenv(env, "HOME");
	tmp_pwd = getcwd(NULL, 0);
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		g_exit_status = 1 * 256;
		return (env);
	}
	else if (chdir(home) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		g_exit_status = 256;
		return (env);
	}
	else
	{
		pwd = ft_search_val(env, "PWD=");
		if (!pwd)
		{
			new_pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
			env = ft_add_var(new_pwd, env);
			oldpwd = ft_search_val(env, "OLDPWD=");
			*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
			g_exit_status = 0;
			return (env);
		}
		else
		{
			free(*pwd);
			*pwd = ft_strjoin("PWD=", home);
			oldpwd = ft_search_val(env, "OLDPWD=");
			free(*oldpwd);
			*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
			free(tmp_pwd);
		}
	}
	g_exit_status = 0;
	return (env);
}

char	**ft_old_pwd(char **env)
{
	char	**old_pwd;
	char	*pwd;

	pwd = ft_getenv(env, "PWD=");
	old_pwd = ft_search_val(env, "OLDPWD=");
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
	}
	if (!old_pwd)
		env = ft_add_var("OLDPWD=", env);
	free(*old_pwd);
	*old_pwd = ft_strjoin("OLDPWD=", pwd);
	printf("pwd %s\n", pwd);
	printf("tmp_pwd %s\n", *old_pwd);
	return (env);
}

char	**ft_new_pwd(char **env)
{
	char	**pwd;
	char	*new_pwd;
	char	*tmp_pwd;

	pwd = ft_search_val(env, "PWD");
	if (!pwd)
	{
		new_pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
		env = ft_add_var(new_pwd, env);
		return (env);
	}
	else
	{
		free(*pwd);
		tmp_pwd = getcwd(NULL, 0);
		*pwd = ft_strjoin("PWD=", tmp_pwd);
		free(tmp_pwd);
	}
	return (env);
}

char	**ft_cd_point(char **env)
{
	ft_putstr_fd("cd: error retrieving current directory: \
	getcwd: cannot access parent directories: No such file or directory\n", 2);
	g_exit_status = 0;
	return (env);
}

char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*old_pwd;

	old_pwd = ft_getenv(env, "OLDPWD");
	if (!old_pwd)
		env = ft_add_var("OLDPWD=", env);
	if (n_cmd == 1 || (n_cmd == 2 && (ft_strcmp(cmd[1], "~") == 0 \
	|| ft_strcmp(cmd[1], "--") == 0 || ft_strcmp(cmd[1], "#") == 0)))
	{
		env = ft_home(env);
		return (env);
	}
	else if (getcwd(NULL, 0) == NULL && ft_strcmp(cmd[1], ".") == 0)
	{
		env = ft_cd_point(env);
		return (env);
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			g_exit_status = 1 * 256;
			return (env);
		}
		else
		{
			env = ft_old_pwd(env);
			env = ft_new_pwd(env);
			g_exit_status = 0;
			return (env);
		}
	}
}
