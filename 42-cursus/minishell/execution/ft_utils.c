/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:40:33 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 20:41:10 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sorting(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) > 0)
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}

int	compaire(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] != '=' && str2[i] != '='
		&& str2[i] != '+')
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	if ((str1[i] == '\0' || str1[i] == '=' || str1[i] == '+')
		&& (str2[i] == '\0' || str2[i] == '=' || str2[i] == '+'))
		return (0);
	else
		return (1);
}

int	already_exist(char *str)
{
	char	**env;
	int		i;

	env = *get_env();
	i = 0;
	while (env[i])
	{
		if (compaire(env[i], str) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	count_valid_av(char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		if (check_valid_arg(av[i]) == 0 && already_exist(av[i]) == -1)
			count++;
		i++;
	}
	return (count);
}

int	check_sign(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '=')
			return (1);
		else if (av[i] == '+' && av[i + 1] == '=')
			return (0);
		i++;
	}
	return (-1);
}
