/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:16:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/26 01:53:54 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "ft_printf.h"

int	calc_shortest(t_lem_map *map, int nbr, char *path)
{
	int	i;

	i = 0;
	if (map->occuped)
		return (-1);
	map->occuped = 1;
	if (map == getset_endmap(NULL))
	{
		ft_printf("%s%s\n", path, map->name);
		return (nbr);
	}
	while (map->next[i])
	{
		return (calc_shortest(map->next[i], nbr + 1,
								ft_strjoin(path, map->name)));
	}
	return (-1);
}
