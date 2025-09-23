/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:51:48 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 22:15:00 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_lvl2(char **env, int *j, int lvl)
{
	char	*shlvl;
	int		i;

	i = 0;
	lvl = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_strdup(env[i] + 6);
			if (!shlvl)
				return (lvl);
			lvl = ft_atoi(shlvl);
			break ;
		}
		i++;
	}
	*j = i;
	return (lvl);
}

int	find_str(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	shell_lvl(char **env)
{
	int		i;
	int		lvl;
	char	*new_shlvl;

	lvl = 0;
	lvl = shell_lvl2(env, &i, lvl);
	if (lvl >= 1000)
	{
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putstr_fd(ft_itoa(lvl + 1), 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		lvl = 1;
	}
	else if (lvl < 0)
		lvl = 0;
	else
		lvl++;
	new_shlvl = ft_itoa(lvl);
	if (!new_shlvl)
		return ;
	env[i] = ft_strjoin("SHLVL=", new_shlvl);
}

int	count_str(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			j--;
		if (!ft_strncmp(env[i], "_=", 2))
			j--;
		if (!ft_strncmp(env[i], "SHLVL=", 6))
			j--;
		i++;
	}
	return (j);
}

void	check_cwd(char **env)
{
	char	*holder;
	char	*cwd;

	*get_env() = get_copy_with_malloc(env);
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		printf("shell-init: error retrieving current directory: getcwd: ");
		printf("cannot access parent directories: No such file or directory\n");
		g_data.pwd = ft_strdup("pwd: error: getcwd: cannot access directories");
	}
	else
	{
		free(cwd);
		holder = getcwd(NULL, 0);
		g_data.pwd = ft_strdup(holder);
		free(holder);
		shell_lvl(*get_env());
	}
	g_data.flag_f_export = 1;
}
