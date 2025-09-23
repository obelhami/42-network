/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:20 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 16:15:23 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_av(char **av, char **new_env, int *j, int index)
{
	int		temp;
	char	*holder;
	int		i;

	i = *j;
	holder = NULL;
	temp = already_exist(av[i]);
	if (check_sign(av[i]) == 1)
		new_env[temp] = cm_strdup(av[i++]);
	else if (check_sign(av[i]) == 0)
	{
		index = 0;
		while (av[i][index] != '=')
			index++;
		if (cm_strchr(new_env[temp], '=') == NULL)
		{
			holder = new_env[temp];
			new_env[temp] = ft_ft_strjoin(new_env[temp], "=");
		}
		holder = new_env[temp];
		new_env[temp] = ft_ft_strjoin(new_env[temp], &av[i++][index + 1]);
	}
	else
		i++;
	*j = i;
}

char	**copy_env(char **env, int *index, char **av)
{
	int		count;
	char	**new_env;
	int		i;

	count = count_valid_av(av);
	new_env = ft_malloc(sizeof(char *) * (dblptr_len(env) + count + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = cm_strdup(env[i]);
		i++;
	}
	*index = i;
	return (new_env);
}

void	change_av(char **av, int j, int index)
{
	if (check_sign(av[j]) == 0)
	{
		index = 0;
		while (av[j][index] != '+')
			index++;
		while (av[j][index])
		{
			av[j][index] = av[j][index + 1];
			index++;
		}
	}
}

char	**get_new_env(char **av, char **env, int *flag)
{
	int		i;
	int		j;
	char	**new_env;
	int		index;

	index = 0;
	new_env = copy_env(env, &i, av);
	j = 1;
	while (av[j])
	{
		if (valid__v(av, &j, flag) == 1)
			continue ;
		if (already_exist(av[j]) != -1)
			add_av(av, new_env, &j, index);
		else
		{
			change_av(av, j, index);
			new_env[i++] = cm_strdup(av[j++]);
			new_env[i] = NULL;
			*get_env() = new_env;
		}
	}
	new_env[i] = NULL;
	return (new_env);
}
