/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoussam <nmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:01:45 by nmoussam          #+#    #+#             */
/*   Updated: 2023/01/12 21:35:03 by nmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_jointo_old(char **env, char *arg);
char	**ft_search_val(char **env, char *var);
char	**ft_add_var(char *var, char **env);

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
		printf("minishell: cd: HOME not set\n");
		exit_status = 1;
		return (env);
	}
	else if (chdir(home) == -1)
	{
		printf("minishell: cd: %s\n", strerror(errno));
		exit_status = 256;
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
			exit_status = 0;
			return (env);
		}
		else
		{
			*pwd = ft_strjoin("PWD=", home);
			oldpwd = ft_search_val(env, "OLDPWD=");
			*oldpwd = ft_strjoin("OLDPWD=", tmp_pwd);
		}
	}
	exit_status = 0;
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
	*old_pwd = ft_strjoin("OLDPWD=", pwd);
	return (env);
}

char	**ft_new_pwd(char **env)
{
	char	**pwd;
	char	*new_pwd;

	pwd = ft_search_val(env, "PWD");
	if (!pwd)
	{
		new_pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
		env = ft_add_var(new_pwd, env);
		return (env);
	}
	else
		*pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
	return (env);
}

char	**ft_cd_point(char **env)
{
	printf("cd: error retrieving current directory: \
	getcwd: cannot access parent directories: No such file or directory\n");
	exit_status = 0;
	return (env);
}

char	**ft_cd(int n_cmd, char **cmd, char **env)
{
	char	*old_pwd;
	char	*pwd;

	old_pwd = ft_getenv(env, "OLDPWD");
	if (!old_pwd)
		env = ft_add_var("OLDPWD=", env);
	pwd = getcwd(NULL, 0);
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
			printf("minishell: cd: %s\n", strerror(errno));
			exit_status = 1;
			return (env);
		}
		else
		{
			env = ft_old_pwd(env);
			env = ft_new_pwd(env);
			exit_status = 0;
			return (env);
		}
	}
}
