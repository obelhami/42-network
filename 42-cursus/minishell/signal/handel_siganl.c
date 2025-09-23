/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_siganl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:17:38 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:36:37 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		exit_s(130);
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	handle_heredoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		close(set_fd(0, 1));
		free_g();
		write(1, "\n", 1);
		exit(2);
	}
}
