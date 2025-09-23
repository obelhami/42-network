/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <obelhami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 06:39:08 by obelhami          #+#    #+#             */
/*   Updated: 2024/12/29 23:52:55 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	*create_ambient(char **split)
{
	t_ambient		*ambient;
	char			**rgb;
	double			light_ratio;

	ambient = alloc(sizeof(t_ambient));
	if (ft_dblptrlen(split) != 3)
		ft_error("Error: the number of arguments is invalid\n");
	light_ratio = ft_atof(split[1]);
	if (light_ratio < 0.0 || light_ratio > 1.0)
		ft_error("Error: the light ratio must be between 0 and 1\n");
	ambient->lighting_ratio = light_ratio;
	rgb = ft_split(split[2], ',');
	ft_check_rgb(rgb);
	fill_rgb(&ambient->color, rgb);
	return (ambient);
}
