/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:41:43 by ybahij            #+#    #+#             */
/*   Updated: 2024/10/02 22:45:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define PIPE 1
# define REDIRECTION 2
# define HEREDOC 3
# define EXEC 4
# define AND 5
# define OR 6

# define MIN -9223372036854775808
# define MAX 9223372036854775807

typedef struct s_cmd
{
	int					type;
}						t_cmd;

typedef struct s_redir
{
	int					type;
	char				*file;
	int					fd;
	int					mode;
	t_cmd				*next;
}						t_redir;

typedef struct s_exec
{
	int					type;
	char				**av;
}						t_exec;

typedef struct s_pipe
{
	int					type;
	t_cmd				*left;
	t_cmd				*right;
}						t_pipe;

typedef struct s_heredoc
{
	int					type;
	char				*content;
	t_cmd				*next;
}						t_heredoc;

typedef struct s_and
{
	int					type;
	t_cmd				*left;
	t_cmd				*right;
}						t_and;

typedef struct s_or
{
	int					type;
	t_cmd				*left;
	t_cmd				*right;
}						t_or;

typedef struct s_lexer
{
	struct s_lexer		*prev;
	char				*content;
	char				type;

	char				*b_appand;
	struct s_lexer		*next;
}						t_lexer;

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_pid
{
	int					pid;
	struct s_pid		*next;
}						t_pid;

typedef struct s_global
{
	int					status;
	int					fall;
	int					heredoc_fd;
	t_garbage			*garbage;
	t_garbage			*p_garbage;
	char				*pwd;
	char				*cp_pwd;
	int					flag;
	char				*old_pwd;
	t_pid				*pid;
	char				*path;
	int					pipe;
	int					flage;
	char				*check_oldpwd;
	int					flag_f_export;
}						t_global;

extern t_global			g_data;

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

void					ft_putstr_fd(char *s, int fd);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
size_t					ft_strlen(const char *s);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strchr(const char *s, int c);
int						ft_strncmp(char *s1, char *s2, size_t n);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *s1);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char *s1, char *s2);
char					**ft_split(char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*cm_strchr(const char *s, int c);
char					*ft_ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_ft_strdup(const char *s1);
char					*ft__strjoin(char *s1, char *s2);
int						ft_strncmp1(char *s1, char *s2, size_t n);

//------------added functions----------------//

t_lexer					*ft_lstlast(t_lexer*lst);
void					ft_lstadd_back(t_lexer**lst, t_lexer*new);
t_lexer					*lexer(char *input, char type);
int						is_space(char c);
t_lexer					*ferst_s(char *input);
int						free_list(t_lexer*head);
void					print_tree(t_cmd *tree);
char					*dellt_q_char(char *tmp);
char					*cheak_env(char *str, char **env);
int						qoute(int *k, char *input, t_lexer**head);
void					free_digit(char *input, int k, int j, t_lexer**g_head);
int						cheak_digit(char *input, int *i);
int						redir_o(char *input, int *j, t_lexer**head);
int						redir_i(char *input, int *j, t_lexer**head);
int						redir(char *input, int *i, t_lexer**head);
int						r_pipe(char *input, int *j, t_lexer**head);
int						n_cmd(char *input, int *j, t_lexer**head);
int						and_or(char *input, int *i, t_lexer**head);
int						pars_quote(char *content);
int						pars_(t_lexer*tmp, char *newline);
void					count_herdoc(t_lexer*tmp);
char					*quote_(char *content);
char					*herdoc_appand(char *content, char type, char **g_env);
int						heandal_herdoc(t_lexer*tmp, char **g_env);
int						cmd_syntax(t_lexer*tmp, char **g_env, char *newline,
							t_lexer*tmp2);
void					free_(t_lexer*cmd);
int						appand_in_fille(t_lexer*cmd, int fd, char hold);
void					free_array(char **str);
int						expand_w(t_lexer*cmd);
int						expand(t_lexer*cmd);
char					*dellt_q(t_lexer*cmd, int i);
int						del_quote(t_lexer*cmd);
t_lexer					*split_1(t_lexer*head, char **str, int i);
t_lexer					*spilt_(t_lexer*head, int i);
int						split_cmd(t_lexer*head);
int						get_cmd_len(t_lexer*token);
char					**get_cmd_args(t_lexer*token);
t_cmd					*parse_cmd(t_lexer*token);
void					handle_redirection(t_redir *redir, t_lexer*token);
t_cmd					*herdoc_construct(t_lexer*token, t_lexer*head,
							char **env);
t_cmd					*redir_construct(t_lexer*token, t_lexer*head,
							char **env);
t_cmd					*parse_redir(t_lexer*head, char **env);
t_cmd					*parse_pipe(t_lexer*head, char **env);
t_cmd					*parse_or(t_lexer*head, char **env);
t_cmd					*parse_and(t_lexer*head, char **env);
t_lexer					*peek(t_lexer*head, char type);
int						appand_u(int *j, int i, t_lexer*cmd, int fd);
char					*herdoc_appand1(char *content, char **g_env, char *str,
							int *i);
int						syntax_error_(t_lexer*tmp, char *newline);
t_lexer					*syntax_error(t_lexer*tmp, char *newline);
int						pars_pipe_(t_lexer*tmp, char *newline);
int						parenthesis(char *input, int *i, t_lexer**head);
void					free_garbage(void);
void					add_garbage(void *content);
void					*ft_malloc(size_t size);
void					free_g(void);
int						pars_parenthesis(t_lexer*tmp, char **g_env);
t_cmd					*parenthesis_c(t_lexer*head, char **env);
int						token_cmd(char *line, t_lexer**cmd, char **env,
							char *newline);
char					*remaove_parenthesis(char *content);
void					handle_signal(int sig);
void					handle_heredoc_signal(int sig);
void					handel_signal_(void);
int						handle_heredoc(t_lexer*tmp, char **g_env);
void					handle_signal2(int sig);
char					*ft_ft_strjoin(const char *s1, const char *s2);
char					**ft_ft_split(const char *str, char c);
void					ft_putstr(char *s);
int						ft_strcmp(char *s1, char *s2);
int						runcmd(t_cmd *cmd, char **env, int i);
int						builtins(t_exec *exec, char **env);
char					*cm_strdup(const char *s1);
char					**get_copy_with_malloc(char **env);
int						dblptr_len(char **dblptr);
char					***get_env(void);
int						ft_is_alpha(char c);
char					*ft_get_env(char *name, char **env);
void					cm_free(char **str);
void					exit_s(int status);
int						ret_status(void);
t_garbage				**get_head(void);
int						set_fd(int fd, int i);
void					read_herdoc(int fd, char *delim);
void					free_g_p(void);
void					ft_unset(char **av, char **env);
void					ft_export(char **av, char **env);
void					heandl_signal_child(int status);
char					*dellt_escap(char *str);
void					dellt__(t_lexer*tmp);
int						heredoc(t_heredoc *cmd, char **env, int i);
int						check_dir(char *cmd);
int						check_exit_status(int status);
int						ft_pipe(t_pipe *cmd, char **env, int i);
int						redirection(t_redir *cmd, char **env, int i);
int						execute(t_exec *cmd, char **env);
void					sig_handel(int sig);
void					ft_signals(void);
char					**get_new_env(char **av, char **env, int *flag);
int						check_sign(char *av);
int						check_valid_arg(char *av);
int						count_valid_av(char **av);
int						compaire(char *s1, char *s2);
int						already_exist(char *str);
int						c_for_unset(char **av, char *env);
int						check_exist(char **av, char **env);
int						str_digit(char *str);
long long				ft_atoll(const char *str);
void					ft_export(char **av, char **env);
void					ft_cd(char **av);
void					ft_echo(char **av);
void					ft_pwd(void);
void					ft_env(char **env);
void					ft_exit(char **av);
void					ft_unset(char **av, char **env);
char					**sorting(char **str);
int						valid__v(char **av, int *j, int *flag);
void					change_pwd(char *name);
void					fil_pwd_oldpwd(void);
int						check_n(char **av, int *i);
int						check_nbr_n(char **av);
void					add_env(char **new_env, int *j, char **env);
char					***get_env(void);
char					**new_envi(void);
int						find_str(char **env, char *str);
int						count_str(char **env);
void					check_cwd(char **env);
void					free_line(char *line);
void					exit_execve(void);
void					ft_print_error(char *cmd, char *error, int status);

#endif
