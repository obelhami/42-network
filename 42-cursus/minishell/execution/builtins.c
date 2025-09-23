/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:44 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 20:41:22 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cm_strdup(const char *s1)
{
	int		i;
	char	*dest;

	if (!s1)
		return (ft_strdup(""));
	dest = ft_malloc((ft_strlen(s1) + 1) * 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	str_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	res_bigger_than_ll(const char *str, int i, int sign)
{
	int	n;

	n = 0;
	if (str[i + 1])
	{
		n = str[i + 1] - '0';
		if (str[i + 2])
		{
			g_data.flag = 1;
			return (-1);
		}
		if (n > 7 && sign == 1)
		{
			g_data.flag = 1;
			return (-1);
		}
		else if (n > 8 && sign == -1)
		{
			g_data.flag = 1;
			return (-1);
		}
	}
	return (0);
}

long long	ft_atoll(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					i;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		if ((res >= 922337203685477580))
		{
			if (res_bigger_than_ll(str, i, sign))
				return (-1);
		}
		i++;
	}
	return (res * sign);
}

int	builtins(t_exec *exec, char **env)
{
	if (ft_strcmp(exec->av[0], "cd") == 0)
		ft_cd(exec->av);
	else if (ft_strcmp(exec->av[0], "echo") == 0)
		ft_echo(exec->av);
	else if (ft_strcmp(exec->av[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(exec->av[0], "export") == 0)
		ft_export(exec->av, env);
	else if (ft_strcmp(exec->av[0], "unset") == 0)
		ft_unset(exec->av, env);
	else if (ft_strcmp(exec->av[0], "env") == 0)
		ft_env(env);
	else if (ft_strcmp(exec->av[0], "exit") == 0)
		ft_exit(exec->av);
	else
		return (0);
	return (1);
}
