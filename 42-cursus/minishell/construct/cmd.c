/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:47:48 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:29:10 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_cmd_len(t_lexer*token)
{
	int		len;
	t_lexer	*tmp;

	len = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == 'w' || tmp->type == 'q')
			len++;
		tmp = tmp->next;
	}
	return (len);
}

char	**get_cmd_args(t_lexer*token)
{
	char	**str;
	int		len;
	t_lexer	*tmp;
	int		i;

	len = 0;
	len = get_cmd_len(token);
	str = ft_malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	tmp = token;
	i = 0;
	while (tmp)
	{
		if (tmp->type == 'w' || tmp->type == 'q')
		{
			str[i] = ft_ft_strdup(tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	str[i] = NULL;
	return (str);
}

t_cmd	*parse_cmd(t_lexer*token)
{
	t_exec	*cmd;

	cmd = ft_malloc(sizeof(t_exec));
	cmd->type = EXEC;
	cmd->av = get_cmd_args(token);
	return ((t_cmd *)cmd);
}

t_lexer	*peek(t_lexer*head, char type)
{
	while (head)
	{
		if (head->type == type)
			return (head);
		head = head->next;
	}
	return (NULL);
}
