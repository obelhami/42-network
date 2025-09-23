/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:37:15 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 22:00:19 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n(char **av, int *i)
{
	int	j;

	while (av[*i] && ft_strncmp(av[*i], "-n", 2) == 0)
	{
		j = 1;
		while (av[*i][j] == 'n')
			j++;
		if (av[*i][j] == '\0')
			(*i)++;
		else
			break ;
	}
	return (0);
}

int	check_nbr_n(char **av)
{
	int	j;

	j = 1;
	if (av[1][0] == '-')
	{
		while (av[1][j] == 'n')
			j++;
		if (av[1][j] == '\0')
			return (1);
	}
	return (0);
}

void	ft_echo(char **av)
{
	int	i;

	i = 1;
	check_n(av, &i);
	if (av[1] == NULL)
	{
		ft_putstr("\n");
		exit_s(0);
		return ;
	}
	while (av[i])
	{
		ft_putstr(av[i]);
		if (av[i + 1] && av[i][0] != '\0')
			ft_putstr(" ");
		i++;
	}
	if (check_nbr_n(av) == 0)
		ft_putstr("\n");
	exit_s(0);
}
