/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:19:11 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:55:53 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_pwd(char *name)
{
	char	*holder;
	char	**tmp;

	tmp = ft_malloc(sizeof(char *) * 3);
	if (ft_strcmp(name, "PWD") == 0 && ft_get_env("PWD", *get_env()))
	{
		holder = getcwd(NULL, 0);
		tmp[0] = ft_strjoin("PWD=", holder);
		tmp[1] = ft_strjoin("PWD=", holder);
		tmp[2] = NULL;
		g_data.pwd = ft_strdup(holder);
		free(holder);
		g_data.flag_f_export = 1;
		ft_export(tmp, *get_env());
	}
	else if (ft_strcmp(name, "OLDPWD") == 0 && ft_get_env("OLDPWD", *get_env()))
	{
		tmp[0] = ft_strjoin("OLDPWD=", g_data.pwd);
		tmp[1] = ft_strjoin("OLDPWD=", g_data.pwd);
		tmp[2] = NULL;
		g_data.old_pwd = ft_strdup(g_data.pwd);
		g_data.flag_f_export = 1;
		ft_export(tmp, *get_env());
	}
	return ;
}

void	fil_pwd_oldpwd(void)
{
	char	*holder;
	char	**tmp;

	tmp = ft_malloc(sizeof(char *) * 3);
	holder = getcwd(NULL, 0);
	g_data.cp_pwd = ft_strdup(holder);
	g_data.old_pwd = ft_strdup(g_data.pwd);
	g_data.pwd = ft_strdup(holder);
	if (ft_strcmp(g_data.check_oldpwd, "1") == 0)
	{
		tmp[0] = ft_strjoin("OLDPWD=", g_data.old_pwd);
		tmp[1] = ft_strjoin("OLDPWD=", g_data.old_pwd);
		tmp[2] = NULL;
		ft_export(tmp, *get_env());
	}
	free(holder);
	exit_s(0);
}

void	ft_cd2(void)
{
	if (chdir(ft_get_env("HOME", *get_env())) == -1)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		exit_s(1);
	}
	else
	{
		g_data.old_pwd = ft_strdup(g_data.pwd);
		g_data.pwd = ft_strdup(ft_get_env("HOME", *get_env()));
		exit_s(0);
	}
}

void	ft_cd(char **av)
{
	change_pwd("OLDPWD");
	if (dblptr_len(av) > 2)
	{
		printf("too many arguments\n");
		exit_s(1);
		return ;
	}
	if (av[1] == NULL)
	{
		ft_cd2();
		return ;
	}
	else if (chdir(av[1]) == -1)
	{
		perror("minishell");
		exit_s(1);
	}
	else
		fil_pwd_oldpwd();
	if (chdir(av[1]) != -1)
		change_pwd("PWD");
}
