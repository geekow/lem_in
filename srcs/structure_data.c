/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:58:43 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/26 00:23:44 by jjacobi          ###   ########.fr       */
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
	list = getset_connection(NULL, 0);
	while (list)
	{
		connec = (t_lem_connection*)list->content;
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

t_lem_map	*get_map_add_with_name(char *name)
{
	t_lem_map	*result;
	t_list		*list;

	result = getset_startmap(NULL);
	if (ft_strcmp(result->name, name) == 0)
		return (result);
	result = getset_endmap(NULL);
	if (ft_strcmp(result->name, name) == 0)
		return (result);
	list = getset_map(NULL);
	while (list)
	{
		result = (t_lem_map*)list->content;
		if (ft_strcmp(result->name, name) == 0)
			return (result);
		list = list->next;
	}
	return (NULL);
}

void		get_next_ptrs(t_lem_map *map, t_list *list)
{
	int					i;
	t_list				*previous;
	t_lem_connection	*connec;

	i = 0;
	previous = NULL;
	while (list)
	{
		connec = (t_lem_connection*)list->content;
		if (ft_strcmp(connec->one, map->name) == 0)
			map->next[i++] = get_map_add_with_name(connec->two);
		else if (ft_strcmp(connec->two, map->name) == 0)
			map->next[i++] = get_map_add_with_name(connec->one);
		if (ft_strcmp(connec->one, map->name) == 0 ||
			ft_strcmp(connec->two, map->name) == 0)
			list = remove_connection(previous, list, connec);
		else
		{
			previous = list;
			list = list->next;
		}
	}
}

int			structure_data(t_lem_map *map)
{
	int i;

	i = 0;
	map->next = alloc_next_ptrs(map);
	get_next_ptrs(map, getset_connection(NULL, 0));
	while (map->next[i] != NULL)
	{
		if (structure_data(map->next[i++]) == -1)
			return (-1);
	}
	return (0);
}
