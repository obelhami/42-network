/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:57:27 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:58:08 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	heredoc(t_heredoc *cmd, char **env, int i)
{
	int	fd[2];
	int	pid;
	int	stdin_copy;
	int	status;

	pipe(fd);
	pid = fork();
	stdin_copy = dup(0);
	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], cmd->content, ft_strlen(cmd->content));
		close(fd[1]);
		close(stdin_copy);
		free_g();
		exit(0);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	status = runcmd(cmd->next, env, i);
	dup2(stdin_copy, 0);
	close(stdin_copy);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	return (status);
}
