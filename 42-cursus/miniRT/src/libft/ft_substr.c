/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:33:09 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/30 00:10:44 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (!s[0])
		return ((char *)ft_calloc(1, sizeof(char)));
	if (start > ft_strlen(s))
		substr = alloc(sizeof(char) * 1);
	else if (len < ft_strlen(s + start))
		substr = alloc(sizeof(char ) * (len + 1));
	else
		substr = alloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!substr)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
		while (s[start] && i < len)
			substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}
