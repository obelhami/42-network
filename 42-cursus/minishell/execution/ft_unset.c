/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:39:51 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 19:57:40 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_exist2(char **av, char **env, int *k, int *count)
{
	int	j;
	int	index;
	int	i;

	i = *k;
	j = 0;
	index = 0;
	while (env[j])
	{
		while ((av[i][index] == env[j][index]) && (av[i][index]
				&& env[j][index]))
			index++;
		if ((av[i][index] == '\0' && env[j][index] == '=')
			|| (av[i][index] == '\0' && env[j][index] == '\0'))
		{
			count++;
			break ;
		}
		j++;
	}
	i++;
	*k = i;
}

int	check_exist(char **av, char **env)
{
	int	i;
	int	index;
	int	count;

	count = 0;
	i = 1;
	index = 0;
	while (av[i])
		check_exist2(av, env, &i, &count);
	return (count);
}

int	c_for_unset2(char *env, char **av)
{
	int	j;
	int	i;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (env[j] != '=' && av[i][j] != '\0' && av[i][j] == env[j])
			j++;
		if ((av[i][j] == '\0' && env[j] == '=') || (av[i][j] == '\0'
				&& env[j] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

int	c_for_unset(char **av, char *env)
{
	int	i;

	if (c_for_unset2(env, av) == 1)
		return (0);
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "PATH") == 0)
			g_data.path = NULL;
		if (ft_strcmp(av[i], "PWD") == 0)
			g_data.pwd = NULL;
		else if (ft_strcmp(av[i], "OLDPWD") == 0)
		{
			g_data.old_pwd = NULL;
			g_data.check_oldpwd = NULL;
		}
		i++;
	}
	return (1);
}

void	ft_unset(char **av, char **env)
{
	int		i;
	int		j;
	int		counter;
	char	**new_env;

	counter = check_exist(av, env);
	new_env = ft_malloc(sizeof(char *) * (dblptr_len(env) - (counter) + 1));
	i = 0;
	j = 0;
	while (env[i])
	{
		if (c_for_unset(av, env[i]) == 1)
		{
			new_env[j] = cm_strdup(env[i]);
			j++;
			i++;
		}
		else
			i++;
	}
	new_env[j] = NULL;
	*get_env() = new_env;
	exit_s(0);
	g_data.flag_f_export = 0;
}
