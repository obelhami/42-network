/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:46 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 16:27:35 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export2(int *flag, char **copy_env)
{
	int	i;
	int	j;

	i = 0;
	sorting(copy_env);
	while (copy_env[i])
	{
		j = 0;
		*flag = 0;
		write(1, "declare -x ", 11);
		while (copy_env[i][j])
		{
			write(1, &copy_env[i][j], 1);
			if (copy_env[i][j] == '=' && *flag == 0)
			{
				*flag = 1;
				write(1, "\"", 1);
			}
			j++;
		}
		if (*flag == 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_export(char **av, char **env)
{
	char	**copy_env;
	int		flag;

	flag = 0;
	if (av[1] == NULL || av[1][0] == '\0')
	{
		copy_env = get_copy_with_malloc(env);
		ft_export2(&flag, copy_env);
	}
	else
	{
		copy_env = get_new_env(av, env, &flag);
		*get_env() = copy_env;
	}
	if (flag == 0)
		exit_s(0);
}
