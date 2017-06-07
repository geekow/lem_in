/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 02:34:06 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 03:15:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_connections(void)
{
	t_list				*tmp;
	t_list				*cache;
	t_lem_connection	*content;

	tmp = getset_connection(NULL, 0);
	while (tmp)
	{
		content = tmp->content;
		free(content->one);
		free(content->two);
		free(content);
		cache = tmp->next;
		free(tmp);
		tmp = cache;
	}
	getset_connection(NULL, 1);
}

void	clear_map_struct(t_lem_map *map)
{
	free(map->name);
	free(map->next);
	free(map);
}

void	clear_maps(void)
{
	t_list		*tmp;
	t_list		*cache;
	t_lem_map	*content;

	tmp = getset_map(NULL);
	while (tmp)
	{
		content = tmp->content;
		clear_map_struct(content);
		cache = tmp->next;
		free(tmp);
		tmp = cache;
	}
}

void	clear_path(t_list *tmp)
{
	t_list	*cache;

	tmp = get_set_shortest_way(NULL, 0);
	while (tmp)
	{
		cache = tmp->next;
		free(tmp);
		tmp = cache;
	}
}

int		clear_all(t_path *path)
{
	t_path	*tmp;

	tmp = path;
	while (tmp)
	{
		clear_path(tmp->path);
		tmp = tmp->next;
	}
	clear_connections();
	clear_maps();
	clear_map_struct(getset_startmap(NULL));
	clear_map_struct(getset_endmap(NULL));
	ft_freepath(path);
	return (0);
}
