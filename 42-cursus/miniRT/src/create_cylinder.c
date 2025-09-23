/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 05:47:41 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/30 00:50:20 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_diameter_height(t_cylinder *cylinder, char **split)
{
	double	diameter;
	double	height;

	diameter = ft_atof(split[3]);
	if (ft_isfloat(split[3]) || diameter < 0.0)
		ft_error("the range of diameter is invalid\n");
	cylinder->diameter = diameter;
	height = ft_atof(split[4]);
	if (ft_isfloat(split[4]) || height < 0.0)
		ft_error("the range of height is invalid\n");
	cylinder->height = height;
}

static void	check_orientation_vector(t_cylinder *cylinder, char **split)
{
	int		i;
	char	**orientation_vector;

	orientation_vector = ft_split(split[2], ',');
	i = 0;
	while (orientation_vector[i])
	{
		if (ft_isfloat(orientation_vector[i])
			|| (ft_atof(orientation_vector[i]) < -1.00
				|| ft_atof(orientation_vector[i]) > 1.00))
			ft_error("orientation_vector is invalid\n");
		i++;
	}
	if (i != 3)
		ft_error("orientation_vector is invalid\n");
	fill_coordinate(&cylinder->axis_vec, orientation_vector);
}

t_cylinder	*create_cylinder(char **split)
{
	char		**coordinate;
	char		**rgb;
	t_cylinder	*cylinder;

	cylinder = alloc(sizeof(t_cylinder));
	if (ft_dblptrlen(split) != 6)
		ft_error("Error: the number of arguments is invalid\n");
	coordinate = ft_split(split[1], ',');
	ft_check_isfloat(coordinate);
	fill_coordinate(&cylinder->center, coordinate);
	check_orientation_vector(cylinder, split);
	check_diameter_height(cylinder, split);
	rgb = ft_split(split[5], ',');
	ft_check_rgb(rgb);
	fill_rgb(&cylinder->color, rgb);
	cylinder->radius = cylinder->diameter / 2;
	get_bases_centers(cylinder);
	return (cylinder);
}
