/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:29:39 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:48:53 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_error2(char *error, int status, char *av, int flag)
{
	ft_putstr_fd("exit\nminishell: exit:", 2);
	if (av)
	{
		ft_putstr_fd(av, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit_s(status);
	if (flag == 1)
		free_g();
}

void	ft_exit2(char **av)
{
	if (str_digit(av[1]) == 0 && str_digit(av[2]) == 0)
	{
		ft_print_error2("too many arguments", 1, NULL, 0);
		return ;
	}
	else if (str_digit(av[1]) == 0 && str_digit(av[2]) == 1)
	{
		ft_print_error2("too many arguments", 1, NULL, 0);
		return ;
	}
	else if (str_digit(av[1]) == 1 && str_digit(av[2]) == 0)
	{
		ft_print_error2("numeric argument required", 2, av[1], 1);
		exit(2);
	}
	else
	{
		ft_print_error2("numeric argument required", 2, av[1], 1);
		exit(2);
	}
}

void	exit_digit(char **av, char **str)
{
	long long	res;

	res = ft_atoll(str[0]);
	if (res == -1 && g_data.flag)
	{
		ft_print_error2("numeric argument required", 2, av[1], 1);
		free_g();
		exit(2);
	}
	free_g();
	printf("exit\n");
	exit(res);
}

void	ft_exit(char **av)
{
	char		**str;
	long long	res;

	res = 0;
	str = NULL;
	if (!av[1])
	{
		free_g();
		exit(ret_status());
	}
	if (av[2] == NULL)
	{
		str = ft_split(av[1]);
		if (str_digit(av[1]) == 0 && str[1] == NULL)
			exit_digit(av, str);
		else
			ft_print_error2("numeric argument required", 2, av[1], 1);
	}
	else
		ft_exit2(av);
}
