/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:12:31 by obelhami          #+#    #+#             */
/*   Updated: 2023/09/05 04:40:20 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin2(char *tab, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	x;

	j = 0;
	i = 0;
	x = 0;
	while (j < size)
	{
		x = 0;
		while (strs[j][x] != '\0')
			tab[i++] = strs[j][x++];
		x = 0;
		while (sep[x] != '\0' && j < size - 1)
			tab[i++] = sep[x++];
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		len;
	int		i;

	tab = (char *)malloc(1);
	if (size == 0)
		return (tab);
	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1);
	if (size <= 0)
		len = 1;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == 0)
		return (tab);
	return (ft_strjoin2(tab, strs, sep, size));
}
/*
#include <stdio.h>
int main() {
    char *strs[] = {"This", "is", "a", "test"};
    char *sep = "-";
    int size = 4;

    char *result = ft_strjoin(size, strs, sep);

    if (result != NULL) {
        printf("Concatenated string: %s\n", result);
        free(result);
    } else {
        printf("Error: Memory allocation failed.\n");
    }

    return 0;
}
*/
