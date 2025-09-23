/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:05:15 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:18:06 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd__(int *j, char *input, char *t, char holder)
{
	int	i;

	i = *j;
	while (input[i] && !cm_strchr("|<>", input[i]) && !is_space(input[i]))
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			holder = input[i];
			*t = 'q';
			if (input[i + 1])
				i++;
			while (input[i] && input[i] != holder)
				i++;
		}
		if (input[i])
			i++;
	}
	*j = i;
}

int	n_cmd(char *input, int *j, t_lexer**head)
{
	t_lexer	*tmp;
	char	t;
	int		i;
	char	holder;
	char	*str;

	i = *j;
	t = 'w';
	holder = 0;
	cmd__(&i, input, &t, holder);
	str = ft_ft_substr(input, *j, i - *j);
	if (!str)
		return (1);
	tmp = lexer(str, t);
	if (!tmp)
		return (1);
	ft_lstadd_back(head, tmp);
	*j = i;
	return (0);
}

t_lexer	*ferst_s(char *input)
{
	t_lexer	*head;
	int		i;

	i = 0;
	head = NULL;
	while (input[i])
	{
		while (input[i] && is_space(input[i]))
			i++;
		if (input[i] == '|' || input[i] == '<' || input[i] == '>')
		{
			if (r_pipe(input, &i, &head))
				return (NULL);
		}
		else if (input[i] && !is_space(input[i]) && input[i] != '\n'
			&& !cm_strchr("|<>", input[i]))
			if (n_cmd(input, &i, &head))
				return (NULL);
	}
	return (head);
}
