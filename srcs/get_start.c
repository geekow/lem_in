/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:13:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 11:56:18 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_start(t_info *data, char **readed)
{
	int	i;

	i = 0;
	while(readed[i] != NULL)
	{
		if (ft_strcmp(readed[i], "##start") == 0)
		{
			data->map = get_room(readed[++i]);
			data->startname = data->map->name;
			return (0);
		}
		i++;
	}
	return (-1);
}
