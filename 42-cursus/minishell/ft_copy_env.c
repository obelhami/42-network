/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:46:01 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 23:00:37 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**new_envi(void)
{
	char	**new_env;
	char	*pwd;

	new_env = ft_malloc(sizeof(char *) * 4);
	if (!new_env)
		return (NULL);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		printf("shell-init: error retrieving current directory:getcwd: ");
		printf("cannot access parent directories: No such file or directory\n");
		free_g();
		exit(1);
	}
	new_env[0] = ft_strjoin("PWD=", pwd);
	free(pwd);
	new_env[1] = ft_strdup("SHLVL=1");
	new_env[2] = ft_strdup("_=/usr/bin/env");
	new_env[3] = NULL;
	if (!new_env[0])
		return (NULL);
	new_env[1] = NULL;
	g_data.path = ft_strdup("/usr/bin:/bin:/usr/sbin:/sbin");
	g_data.check_oldpwd = ft_strdup("1");
	return (new_env);
}

char	***get_env(void)
{
	static char	**env;

	return (&env);
}

void	add_env(char **new_env, int *j, char **env)
{
	int	i;

	i = *j;
	if (g_data.flag_f_export == 1 && find_str(env, "SHLVL=") == 0)
	{
		new_env[i] = ft_strdup("SHLVL=1");
		i++;
	}
	if (g_data.flag_f_export == 1 && find_str(env, "PWD=") == 0)
	{
		new_env[i] = ft_strjoin("PWD=", g_data.pwd);
		i++;
	}
	if (g_data.flag_f_export == 1 && find_str(env, "_=") == 0)
	{
		new_env[i] = ft_strdup("_=/usr/bin/env");
		i++;
	}
	*j = i;
}

char	**get_copy_with_malloc(char **env)
{
	int		i;
	char	**new_env;

	if (env[0] == NULL)
		return (new_envi());
	new_env = ft_malloc(sizeof(char *) * (dblptr_len(env) + count_str(env)
				+ 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	add_env(new_env, &i, env);
	new_env[i] = NULL;
	g_data.check_oldpwd = ft_strdup("1");
	return (new_env);
}
