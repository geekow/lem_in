/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:58:43 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 04:27:34 by user             ###   ########.fr       */
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

int			alloc_next_ptrs(t_lem_map *map)
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
		return (-1);
	result[i] = NULL;
	map->next = result;
	return (0);
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

t_list		*get_next_ptrs(t_lem_map *map, t_list *list)
{
	int					i;
	t_list				*previous;
	t_lem_connection	*connec;
	t_list				*result;

	i = 0;
	previous = NULL;
	result = NULL;
	while (list)
	{
		connec = (t_lem_connection*)list->content;
		if (ft_strcmp(connec->one, map->name) == 0)
			map->next[i++] = get_map_add_with_name(connec->two);
		else if (ft_strcmp(connec->two, map->name) == 0)
			map->next[i++] = get_map_add_with_name(connec->one);
		if (ft_strcmp(connec->one, map->name) == 0 ||
			ft_strcmp(connec->two, map->name) == 0)
			result = remove_conn_save_next(&list, previous, result,
											map->next[i - 1]);
		else
		{
			previous = list;
			list = list->next;
		}
	}
	return (result);
}

int			structure_data(t_lem_map *map)
{
	t_list		*current;
	t_list		*next;
	t_lem_map	*tmp;

	next = NULL;
	alloc_next_ptrs(map);
	current = get_next_ptrs(map, CONNECTIONS);
	while (current)
	{
		while (current)
		{
			tmp = current->content;
			if (!tmp->next && tmp != getset_endmap(NULL))
			{
				alloc_next_ptrs(tmp);
				if (!next)
					next = get_next_ptrs(tmp, CONNECTIONS);
				else
					ft_lstpushback(next, get_next_ptrs(tmp, CONNECTIONS));
			}
			advance_and_clear(&current, 0);
		}
		current = next;
		next = NULL;
	}
	return (0);
}
