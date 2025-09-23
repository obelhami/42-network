/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:46:23 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:28:38 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_redirection(t_redir *redir, t_lexer*token)
{
	if (token->type == '<')
	{
		redir->mode = O_RDONLY;
		redir->fd = 0;
	}
	else if (token->type == '>')
	{
		redir->mode = O_CREAT | O_WRONLY | O_TRUNC;
		redir->fd = 1;
	}
	else if (token->type == '+')
	{
		redir->mode = O_CREAT | O_WRONLY | O_APPEND;
		redir->fd = 1;
	}
}

t_cmd	*herdoc_construct(t_lexer*token, t_lexer*head, char **env)
{
	t_heredoc	*heredoc;

	heredoc = ft_malloc(sizeof(t_redir));
	heredoc->type = HEREDOC;
	heredoc->content = ft_ft_strdup(token->next->content);
	token->type = 'p';
	token->next->type = 'p';
	heredoc->next = parse_redir(head, env);
	return ((t_cmd *)heredoc);
}

t_cmd	*redir_construct(t_lexer*token, t_lexer*head, char **env)
{
	t_redir	*redir;

	redir = ft_malloc(sizeof(t_redir));
	redir->type = REDIRECTION;
	redir->file = ft_strdup(token->next->content);
	handle_redirection(redir, token);
	token->type = 'p';
	token->next->type = 'p';
	redir->next = parse_redir(head, env);
	return ((t_cmd *)redir);
}

t_cmd	*parse_redir(t_lexer*head, char **env)
{
	t_lexer	*token;

	token = head;
	while (token)
	{
		if (cm_strchr("<>+h", token->type))
			break ;
		token = token->next;
	}
	if (token && cm_strchr("<>+", token->type))
		return (redir_construct(token, head, env));
	else if (token && token->type == 'h')
		return (herdoc_construct(token, head, env));
	else
		return (parse_cmd(head));
}

t_cmd	*parse_pipe(t_lexer*head, char **env)
{
	t_lexer	*token;
	t_pipe	*pipe;

	token = peek(head, '|');
	if (token)
	{
		pipe = ft_malloc(sizeof(t_pipe));
		if (!pipe)
			return (NULL);
		pipe->type = PIPE;
		token->prev->next = NULL;
		token->next->prev = NULL;
		pipe->left = parse_redir(head, env);
		pipe->right = parse_pipe(token->next, env);
		return ((t_cmd *)pipe);
	}
	else
		return (parse_redir(head, env));
}
