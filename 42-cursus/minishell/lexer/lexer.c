/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:42:29 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:18:06 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer	*ft_lstlast(t_lexer*lst)
{
	while (lst != NULL)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_lexer**lst, t_lexer*new)
{
	t_lexer	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

t_lexer	*lexer(char *input, char type)
{
	t_lexer	*head;

	if (!input)
		return (NULL);
	head = ft_malloc(sizeof(t_lexer));
	if (!head)
		return (NULL);
	head->content = ft_ft_strdup(input);
	head->type = type;
	head->b_appand = NULL;
	head->next = NULL;
	head->prev = NULL;
	input = NULL;
	return (head);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	qoute(int *k, char *input, t_lexer**head)
{
	int		j;
	t_lexer	*tmp;
	char	qoute_type;

	j = *k;
	qoute_type = input[j];
	j++;
	while (input[j] && input[j] != qoute_type)
		j++;
	while (input[j] && !is_space(input[j]))
		j++;
	tmp = lexer(ft_substr(input, *k, j - *k), 'q');
	ft_lstadd_back(head, tmp);
	if (input[j])
		j++;
	*k = j;
	return (0);
}
