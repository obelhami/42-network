/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:05:53 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/30 00:03:15 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	check_orientation_vector(t_plane *plane, char **split)
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
	fill_coordinate(&plane->normal_vec, orientation_vector);
}

t_plane	*create_plane(char **split)
{
	char	**coordinate;
	char	**rgb;
	t_plane	*plane;

	plane = alloc(sizeof(t_plane));
	if (ft_dblptrlen(split) != 4)
		ft_error("Error: the number of arguments is invalid\n");
	coordinate = ft_split(split[1], ',');
	ft_check_isfloat(coordinate);
	fill_coordinate(&plane->point_cord, coordinate);
	check_orientation_vector(plane, split);
	rgb = ft_split(split[3], ',');
	ft_check_rgb(rgb);
	fill_rgb(&plane->color, rgb);
	return (plane);
}
