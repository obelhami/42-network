/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:50:59 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 22:01:18 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_error(char *cmd, char *error, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	free_g();
	exit(status);
}

void	exit_execve(void)
{
	perror("execve");
	free_g();
	exit(126);
}
