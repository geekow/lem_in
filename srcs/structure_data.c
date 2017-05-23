/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:58:43 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/24 00:01:16 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_map	*getset_data(t_lem_map *param)
{
	static t_lem_map	*map = NULL;

	if (param)
	{
		map = param;
		return (NULL);
	}
	else
		return (map);
}

t_lem_map	**alloc_next_ptrs(t_lem_map *map)
{
	t_list				*list;
	t_lem_map			**result;
	t_lem_connection	*connec;
	int					i;

	i = 0;
	list = getset_connection(NULL);
	while (list)
	{
		connec = list->content;
		if (ft_strcmp(connec->one, map->name) == 0 ||
			ft_strcmp(connec->two, map->name) == 0)
			i++;
		list = list->next;
	}
	if ((result = (t_lem_map**)malloc(sizeof(t_lem_map*) * (i + 1))) == NULL)
		return (NULL);
	result[i] = NULL;
	return (result);
}

int			get_next_ptrs(t_lem_map *map)
{
	int	i;

	i = 0;
	map->next = alloc_next_ptrs(map);
	while (i != -1)
	{
		// map->next[i++] = ;
		if (map->next[i] == NULL)
			i = -1;
	}
	return (0);
}

int			structure_data(void)
{
	t_lem_map	*result;

	result = getset_startmap(NULL);
	return (0);
}
