/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:58:50 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 22:02:44 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_env(char *name, char **env)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (env[i])
	{
		j = 0;
		k = 0;
		while (env[i][j] && name[k] && (env[i][j] == name[k]))
		{
			j++;
			k++;
		}
		if (env[i][j] == '=' && name[k] == '\0')
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}

int	check_exit_status(int status)
{
	int	signal_number;

	if (((status) & 0x7f) != 0 && ((status) & 0x7f) != 0x7f)
	{
		signal_number = (status) & 0x7f;
		if (signal_number == SIGQUIT)
		{
			ft_putstr_fd("Quit (core dumped)\n", 2);
			return (((status) & 0x7f) + 128);
		}
		else if (signal_number == SIGINT)
		{
			return (((status) & 0x7f) + 128);
		}
	}
	else if (((status) & 0x7f) == 0)
	{
		return ((status >> 8) & 0xff);
	}
	return (-1);
}

void	ft_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

int	check_dir(char *cmd)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
	{
		perror("stat");
		free_g();
		exit(1);
	}
	if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		free_g();
		exit(126);
	}
	return (1);
}

int	runcmd(t_cmd *cmd, char **env, int i)
{
	if (cmd->type == PIPE)
	{
		return (ft_pipe((t_pipe *)cmd, env, i));
	}
	else if (cmd->type == HEREDOC)
	{
		return (heredoc((t_heredoc *)cmd, env, i));
	}
	if (cmd->type == REDIRECTION)
		return (redirection((t_redir *)cmd, env, i));
	if (cmd->type == EXEC)
		return (execute((t_exec *)cmd, env));
	return (1);
}
