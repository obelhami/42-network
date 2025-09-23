/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils_for_parsing.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: obelhami <obelhami@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/25 05:16:06 by obelhami		  #+#	#+#			 */
/*   Updated: 2024/12/25 06:42:18 by obelhami         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_ft_isdigit(rgb[i]) == 1)
			ft_error("Error: the color must be a number\n");
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_error("Error: the color must be between 0 and 255\n");
		i++;
	}
	if (i != 3)
		ft_error("Error: the color must have 3 arguments\n");
}

void	ft_check_isfloat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isfloat(str[i]))
			ft_error("Error: the coordinates must be a number\n");
		i++;
	}
	if (i != 3)
		ft_error("Error: the coordinates must have 3 arguments\n");
}
