/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:31:31 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/26 20:23:13 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_of_src;
	unsigned int	size_of_dest;

	size_of_src = ft_strlen(src);
	size_of_dest = ft_strlen(dest);
	if (size == 0)
		return (size_of_src);
	i = 0;
	while (src[i] != '\0' && size_of_dest + i < (size - 1))
	{
		dest[i + size_of_dest] = src[i];
		i++;
	}
	dest[size_of_dest + i] = '\0';
	if (size_of_dest > size)
		return (size_of_src + size);
	return (size_of_dest + size_of_src);
}
