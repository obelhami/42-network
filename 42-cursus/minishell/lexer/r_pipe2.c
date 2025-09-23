/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_pipe2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:20:21 by obelhami          #+#    #+#             */
/*   Updated: 2024/10/02 22:27:02 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cheak_digit(char *input, int *i)
{
	int		j;
	char	hold;
	int		k;

	j = *i;
	hold = input[j];
	j++;
	k = j;
	if (input[j] == hold)
		j++;
	while (input[j] && is_space(input[j]))
		j++;
	if (input[j] && ft_isdigit(input[j]))
	{
		while (input[j] && ft_isdigit(input[j]))
			j++;
		if (input[j] && cm_strchr("<>", input[j]))
		{
			exit_s(2);
			return (printf(RED
					"minishell: syntax error near unexpected token `%s'\n"
					RESET, ft_substr(input, k, j - k)), 1);
		}
	}
	return (0);
}

int	r_pipe(char *input, int *j, t_lexer**head)
{
	t_lexer	*tmp;
	int		i;

	i = *j;
	if (input[i] == '|')
	{
		tmp = lexer(ft_ft_substr(input, i, 1), '|');
		if (!tmp)
			return (1);
		ft_lstadd_back(head, tmp);
		i++;
	}
	if (input[i] == '<' || input[i] == '>')
	{
		if (redir(input, &i, head))
		{
			return (1);
		}
	}
	*j = i;
	return (0);
}
