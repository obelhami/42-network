/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:48:28 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:27:29 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir__(t_lexer*tmp, char *input, int *j, t_lexer**head)
{
	int	i;

	i = *j;
	if (cheak_digit(input, &i))
		return (1);
	tmp = lexer(ft_substr(input, i, 1), '>');
	if (!tmp)
		return (1);
	ft_lstadd_back(head, tmp);
	i++;
	*j = i;
	return (0);
}

int	redir_o(char *input, int *j, t_lexer**head)
{
	t_lexer	*tmp;
	int		i;

	i = *j;
	tmp = NULL;
	if (input[i] == '>')
	{
		if (input[i + 1] == '>')
		{
			if (cheak_digit(input, &i))
				return (1);
			tmp = lexer(ft_substr(input, i, 2), '+');
			if (!tmp)
				return (1);
			ft_lstadd_back(head, tmp);
			i += 2;
		}
		else
		{
			if (redir__(tmp, input, &i, head))
				return (1);
		}
	}
	*j = i;
	return (0);
}

int	redir__i(t_lexer*tmp, t_lexer**head, char *input, int *j)
{
	int	i;

	i = *j;
	if (cheak_digit(input, &i))
		return (1);
	tmp = lexer(ft_ft_substr(input, i, 1), '<');
	if (!tmp)
		return (1);
	ft_lstadd_back(head, tmp);
	i++;
	*j = i;
	return (0);
}

int	redir_i(char *input, int *j, t_lexer**head)
{
	t_lexer	*tmp;
	int		i;

	i = *j;
	tmp = NULL;
	if (input[i] == '<')
	{
		if (input[i + 1] == '<')
		{
			if (cheak_digit(input, &i))
				return (1);
			tmp = lexer(ft_ft_substr(input, i, 2), 'h');
			if (!tmp)
				return (1);
			ft_lstadd_back(head, tmp);
			i += 2;
		}
		else
		{
			if (redir__i(tmp, head, input, &i))
				return (1);
		}
	}
	*j = i;
	return (0);
}

int	redir(char *input, int *i, t_lexer**head)
{
	int	j;

	j = *i;
	if (input[j] == '<')
	{
		if (redir_i(input, &j, head))
		{
			return (1);
		}
	}
	if (input[j] == '>')
	{
		if (redir_o(input, &j, head))
			return (1);
	}
	*i = j;
	return (0);
}
