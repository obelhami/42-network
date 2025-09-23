/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:26:17 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:44:13 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_handel(int sig)
{
	if (sig == SIGINT)
		printf("\n");
}

void	left_pipe(int *fd, int stdin_copy, t_pipe *cmd, int i)
{
	int	status;

	status = 0;
	signal(SIGINT, heandl_signal_child);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	close(stdin_copy);
	i++;
	status = runcmd(cmd->left, *get_env(), i);
	free_g();
	exit(status);
}

void	righ_pipe(int *fd, int stdin_copy, t_pipe *cmd, int i)
{
	int	status;

	status = 0;
	signal(SIGINT, heandl_signal_child);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	close(stdin_copy);
	i++;
	status = runcmd(cmd->right, *get_env(), i);
	free_g();
	exit(status);
}

int	wait_child(int *fd, int pid, int pid2, int stdin_copy)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	dup2(stdin_copy, 0);
	close(stdin_copy);
	return (0);
}

int	ft_pipe(t_pipe *cmd, char **env, int i)
{
	int	fd[2];
	int	status;
	int	pid;
	int	pid2;
	int	stdin_copy;

	pipe(fd);
	(void)env;
	pid = fork();
	stdin_copy = dup(0);
	status = 0;
	pid2 = 0;
	if (pid == 0)
		left_pipe(fd, stdin_copy, cmd, i);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			righ_pipe(fd, stdin_copy, cmd, i);
	}
	if (i == 0)
		signal(SIGINT, sig_handel);
	wait_child(fd, pid, pid2, stdin_copy);
	return (status);
}
