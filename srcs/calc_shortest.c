/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:16:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 04:22:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

t_list	*add_to_path(t_list *path, char *map_name)
{
	t_list	*tmp;
	t_list	*cpy;
	t_list	*result;

	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	result->content = map_name;
	result->next = NULL;
	if (!path)
		return (result);
	if (!(cpy = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	cpy->content = path->content;
	tmp = cpy;
	while (path->next != NULL)
	{
		if (!(tmp->next = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		path = path->next;
		tmp->next->content = path->content;
		tmp = tmp->next;
	}
	tmp->next = result;
	return (cpy);
}

t_list	*get_set_shortest_way(t_list *list, char reset)
{
	static t_list	*result = NULL;

	if (reset)
		result = NULL;
	else if (list)
		result = list;
	else
		return (result);
	return (NULL);
}

t_list	*calc_shortest(t_lem_map *map, t_list *path)
{
	t_list			*result;
	t_list			*tmp;
	t_current_map	*map_info;
	int				i;

	i = -1;
	result = NULL;
	while (map->next && map->next[++i])
	{
		if (map->next[i] == getset_endmap(NULL))
		{
			while (result)
				advance_and_clear(&result, 1);
			return (get_set_shortest_way(add_to_path(path, map->name), 0));
		}
		if (!(tmp = (t_list*)malloc(sizeof(t_list))) ||
			!(map_info = (t_current_map*)malloc(sizeof(t_current_map))))
			return (NULL);
		map_info->map = map->next[i];
		map_info->path = add_to_path(path, map->name);
		tmp->content = (void*)map_info;
		tmp->next = NULL;
		result = !result ? tmp : ft_lstpushback(result, tmp);
	}
	return (result);
}

void	get_path(t_lem_map *start, t_list *next)
{
	t_list			*current;
	t_current_map	*map;
	t_list			*result;

	current = calc_shortest(start, NULL);
	while (current)
	{
		while (current)
		{
			map = current->content;
			result = calc_shortest(map->map, map->path);
			if (!result && get_set_shortest_way(NULL, 0))
			{
				while (current)
					advance_and_clear(&current, 1);
				while (next)
					advance_and_clear(&next, 1);
				return ;
			}
			next = !next ? result : ft_lstpushback(next, result);
			advance_and_clear(&current, 1);
		}
		current = next;
		next = NULL;
	}
}
