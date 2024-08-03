/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:49 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 16:31:52 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_tab
{
	int					*tab;
	char				*line;
}						t_stack_tab;

typedef struct s_stack_node
{
	int					nbr;
	struct s_stack_node	*next;
}						t_stack_node;

int						number_of_args(int argc, char **argv);
void					check_double(t_stack_node **a);
void					init_stack(t_stack_node **a, char **array);
int						ft_strcmp(const char *s1, const char *s2);
void					check_string(t_stack_node **a, t_stack_node **b,
							char *line, int *tab);
void					ft_checker(t_stack_node **a, t_stack_node **b, int *tab,
							int size);
int						space(char c);
void					free_stack(t_stack_node **a);
void					ft_free(char **array);
int						count_string(char *str);
void					swap(t_stack_node **a);
void					push(t_stack_node **a, t_stack_node **b);
void					rotate(t_stack_node **a);
void					reverse_rotate(t_stack_node **a);
void					rrr(t_stack_node **a, t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
void					check_characters(char **argv, char **array);
void					check_empty_arg(char **argv, char **array);
void					check_args(int argc, char **argv, char **array);
void					check_max_int(char **array);
void					fill_array(char **argv, char **array, int i, int x);
int						*fill_tab(t_stack_node **a, int size);
void					check_sort_tab(t_stack_node **a, int count, int *tab);
void					sort_tab(int *tab, int size);
long					ft_atolong(const char *str);
void					ft_swap(int *a, int *b);
t_stack_node			*new_node(long content, char **array);
int						node_size(t_stack_node *lst);

#endif