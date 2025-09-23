/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:37:50 by youssef           #+#    #+#             */
/*   Updated: 2024/10/02 22:18:06 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	paranthesis__(t_lexer*cmd)
{
	t_lexer	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->type == '(' && tmp->next && cm_strchr("qw", tmp->next->type))
		{
			exit_s(2);
			printf(RED "minishell: syntax error near unexpected token `%s'\n"
				RESET, tmp->next->content);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	cheak_dollar_p(char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i] != '=')
	{
		if (input[i] == '$')
			return (0);
		i++;
	}
	return (1);
}

int	cheak_for_equal(t_lexer*cmd)
{
	t_lexer	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->type == 'w' && cm_strchr(tmp->content, '=')
			&& cm_strchr(tmp->content, '$'))
		{
			if (cheak_dollar_p(tmp->content))
			{
				tmp->content = ft_strjoin("\"", tmp->content);
				if (!tmp->content)
					return (1);
				tmp->content = ft_strjoin(tmp->content, "\"");
				if (!tmp->content)
					return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	token_cmd(char *line, t_lexer**cmd, char **env, char *newline)
{
	t_lexer	*tmp;

	tmp = NULL;
	*cmd = ferst_s(line);
	if (!(*cmd))
		return (1);
	if (cmd_syntax(*cmd, env, newline, tmp))
		return (1);
	if (cheak_for_equal(*cmd))
		return (1);
	if (expand(*cmd))
		return (1);
	if (!(*cmd))
		return (1);
	if (!split_cmd(*cmd))
		return (1);
	del_quote(*cmd);
	dellt__(*cmd);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_lexer	*cmd;

	(void)ac;
	(void)av;
	check_cwd(env);
	line = NULL;
	while (1)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell$ ");
		if (!line)
			free_line(line);
		add_garbage(line);
		if (*line)
			add_history(line);
		if (token_cmd(line, &cmd, *get_env(), "newline"))
			continue ;
		runcmd(parse_pipe(cmd, *get_env()), *get_env(), 0);
	}
	return (0);
}
