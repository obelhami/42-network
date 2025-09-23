/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:15:24 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:59:46 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid_arg(char *av)
{
	int	i;

	i = 1;
	if (ft_is_alpha(av[0]) == 0 && av[0] != '_')
		return (1);
	while (av[i] != '\0' && av[i] != '=' && av[i] != '+')
	{
		if (ft_is_alpha(av[i]) == 0 && ft_isdigit(av[i]) == 0 && av[i] != '_')
			return (1);
		i++;
	}
	if (av[i] == '+' && av[i + 1] != '=')
		return (1);
	return (0);
}

void	sub_env(char **av, int *j, int *flag)
{
	printf("export: `%s': not a valid identifier\n", av[*j]);
	(*j)++;
	exit_s(1);
	*flag = 1;
}

int	valid__v(char **av, int *j, int *flag)
{
	if (check_valid_arg(av[*j]) == 1)
	{
		sub_env(av, j, flag);
		return (1);
	}
	return (0);
}
