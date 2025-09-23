/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:22:20 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:06:24 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dblptr_len(char **dblptr)
{
	int	i;

	i = 0;
	while (dblptr[i])
		i++;
	return (i);
}

void	free_line(char *line)
{
	clear_history();
	printf("exit\n");
	free(line);
	free_g();
	exit(ret_status());
}

void	*ft_malloc(size_t size)
{
	t_garbage	*tmp;
	void		*tmp2;

	tmp2 = malloc(size);
	if (!tmp2)
	{
		g_data.fall = 1;
		printf(MAGENTA "Error: malloc failed\n" RESET);
		free_g();
		exit(1);
	}
	tmp = malloc(sizeof(t_garbage));
	if (!tmp)
	{
		free(tmp2);
		g_data.fall = 1;
		printf(MAGENTA "Error: malloc failed\n" RESET);
		free_g();
		exit(1);
	}
	tmp->content = tmp2;
	tmp->next = *get_head();
	*get_head() = tmp;
	return (tmp2);
}

void	add_garbage(void *content)
{
	t_garbage	*tmp;

	tmp = malloc(sizeof(t_garbage));
	if (!tmp)
	{
		g_data.fall = 1;
		printf(MAGENTA "Error: malloc failed\n" RESET);
		return ;
	}
	tmp->content = content;
	tmp->next = *get_head();
	*get_head() = tmp;
}

void	free_g(void)
{
	t_garbage	*tmp;

	if (!*get_head())
		return ;
	while (*get_head())
	{
		tmp = (*get_head())->next;
		if ((*get_head())->content)
			free((*get_head())->content);
		free(*get_head());
		*get_head() = tmp;
	}
	*get_head() = NULL;
}
