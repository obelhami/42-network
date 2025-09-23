/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:32:40 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 21:51:33 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute3(t_exec *cmd, char **env, int *check)
{
	if ((cmd->av[0][0] == '.' && cmd->av[0][1] == '/') || cmd->av[0][0] == '/')
	{
		if (access(cmd->av[0], F_OK) == -1)
			ft_print_error(cmd->av[0], "No such file or directory", 127);
		if (check_dir(cmd->av[0]) == 0)
		{
			free_g();
			exit(126);
		}
		if (access(cmd->av[0], X_OK) == -1)
			ft_print_error(cmd->av[0], "Permission denied", 126);
		if (execve(cmd->av[0], cmd->av, env) == -1)
		{
			perror("execve");
			free_g();
			exit(1);
		}
		*check = 1;
	}
	if (cmd->av[0][0] == '.' && !cmd->av[0][1] && !cmd->av[1])
		ft_print_error(cmd->av[0], "filename argument required", 2);
}

void	execute4(t_exec *cmd, char **env, char *cmd_path)
{
	if (cmd_path == NULL && g_data.path == NULL)
	{
		if (access(cmd->av[0], F_OK) == -1)
			ft_print_error(cmd->av[0], "No such file or directory", 127);
		if (check_dir(cmd->av[0]) == 0)
		{
			free_g();
			exit(126);
		}
		if (access(cmd->av[0], X_OK) == -1)
			ft_print_error(cmd->av[0], "Permission denied", 126);
		if (execve(cmd->av[0], cmd->av, env) == -1)
		{
			perror("execve");
			free_g();
			exit(1);
		}
		ft_print_error(cmd->av[0], "command not found", 127);
	}
}

void	execute5(t_exec *cmd, char **env, int *check, char *cmd_path)
{
	char	**path;
	int		i;

	i = 0;
	if (cmd_path)
		g_data.path = cmd_path;
	path = ft_ft_split(g_data.path, ':');
	while (path[i])
	{
		path[i] = ft_ft_strjoin(path[i], "/");
		path[i] = ft_ft_strjoin(path[i], cmd->av[0]);
		if (access(path[i], F_OK) == 0)
		{
			if ((cmd->av[0][0] == '.' && cmd->av[0][1] == '.' && !cmd->av[1])
				|| !cmd->av[0][0])
				break ;
			if (execve(path[i], cmd->av, env) == -1)
				exit_execve();
			*check = 1;
		}
		i++;
	}
}

void	execute2(t_exec *cmd, char **env)
{
	char	*cmd_path;
	int		check;

	check = 0;
	ft_signals();
	execute3(cmd, env, &check);
	cmd_path = ft_get_env("PATH", env);
	execute4(cmd, env, cmd_path);
	execute5(cmd, env, &check, cmd_path);
	if (cmd->av[0][0] == '"' || cmd->av[0][0] == '\'')
	{
		ft_print_error(cmd->av[0], "command not found", 127);
		check = 1;
	}
	if (cmd->av[0][0] == '\0')
	{
		free_g();
		exit(127);
		check = 1;
	}
	if (check == 0)
		ft_print_error(cmd->av[0], "command not found", 127);
	free_g();
	exit(0);
}

int	execute(t_exec *cmd, char **env)
{
	int	pid;
	int	status;
	int	i;

	if (cmd->av[0] == NULL)
		return (1);
	if (builtins(cmd, env) == 1)
		return (1);
	pid = fork();
	i = 0;
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
		execute2(cmd, env);
	else
	{
		waitpid(pid, &status, 0);
		exit_s(check_exit_status(status));
	}
	return (ret_status());
}
