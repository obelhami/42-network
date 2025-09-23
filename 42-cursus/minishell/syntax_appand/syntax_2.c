/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:27:38 by ybahij            #+#    #+#             */
/*   Updated: 2024/10/02 22:17:27 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pars_pipe_(t_lexer*tmp, char *newline)
{
	if (!tmp->next)
	{
		printf(RED "minishell: syntax error near unexpected token `%s'\n" RESET,
			newline);
		return (exit_s(2), 0);
	}
	if (cm_strchr("|", tmp->next->type))
	{
		printf(RED "minishell: syntax error near unexpected token `%s'\n" RESET,
			tmp->next->content);
		return (exit_s(2), 0);
	}
	return (1);
}
