/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:26:57 by obelhami          #+#    #+#             */
/*   Updated: 2023/08/23 04:50:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if (i > 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				if ((str[i - 1] < '0')
					|| (str[i - 1] < 'A' && str[i - 1] > '9')
					|| (str[i - 1] < 'a' && str[i - 1] > 'Z')
					|| str[i - 1] > 'z')
					str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
