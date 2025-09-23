/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:50:05 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:53:55 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection(t_redir *cmd, char **env, int i)
{
	int	fd;
	int	std_copy;
	int	status;

	fd = open(cmd->file, cmd->mode, 0644);
	if (fd == -1)
	{
		perror(cmd->file);
		exit_s(1);
		return (0);
	}
	std_copy = dup(cmd->fd);
	dup2(fd, cmd->fd);
	status = runcmd(cmd->next, env, i);
	dup2(std_copy, cmd->fd);
	close(std_copy);
	return (status);
}
