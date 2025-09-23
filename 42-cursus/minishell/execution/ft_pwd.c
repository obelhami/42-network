/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:39:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 20:39:35 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	*holder;

	if (g_data.pwd == NULL || ft_strcmp(g_data.pwd, "") == 0)
	{
		holder = getcwd(NULL, 0);
		if (holder == NULL)
			printf("%s\n", g_data.cp_pwd);
		else
		{
			printf("%s\n", holder);
			free(holder);
		}
	}
	else
		printf("%s\n", g_data.pwd);
	exit_s(0);
}
