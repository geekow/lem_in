/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 01:29:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 01:30:30 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_nbrs(t_path *path)
{
	int	i;

	i = 0;
	while (path)
	{
		i++;
		path = path->next;
	}
	return (i);
}

int		calc_score(int ants, t_path *result)
{
	t_path	*tmp;
	int		average;
	int		shortest;
	int		removed;

	average = ants / path_nbrs(result);
	shortest = result->deep;
	result->ants = average;
	tmp = result->next;
	removed = ants % path_nbrs(result);
	while (tmp)
	{
		removed += tmp->deep - shortest;
		tmp->ants = average - (tmp->deep - shortest);
		tmp = tmp->next;
	}
	while (removed)
	{
		if (!tmp)
			tmp = result;
		tmp->ants += 1;
		tmp = tmp->next;
		removed--;
	}
	return (result->ants + result->deep);
}

t_path	*cpy_and_add(t_path *path, t_list *toadd)
{
	t_path	*result;
	t_path	*cpy;

	if (!toadd || (ft_lstlen(toadd) == 1 && path))
		clear_lst(toadd);
	if (!toadd || (ft_lstlen(toadd) == 1 && path))
		return (path);
	if (!(result = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	cpy = result;
	while (path)
	{
		cpy->current = path->current;
		cpy->deep = path->deep;
		cpy->path = path->path;
		if (!(cpy->next = (t_path*)malloc(sizeof(t_path))))
			return (NULL);
		path = path->next;
		cpy = cpy->next;
	}
	cpy->current = NULL;
	cpy->deep = ft_lstlen(toadd);
	cpy->path = toadd;
	cpy->next = NULL;
	return (result);
}

void	remove_from_data(t_lem_map *map, t_list *path)
{
	int	i;
	int	todell;

	i = 0;
	todell = -1;
	if (!path || !path->next)
		return ;
	while (map->next[i])
	{
		if (map->next[i]->name == path->next->content)
			todell = i;
		i++;
	}
	if (path->next->next && todell != -1)
		remove_from_data(map->next[todell], path->next);
	if (todell != -1)
	{
		map->next[todell]->occuped = 1;
		map->next[todell] = map->next[i - 1];
		map->next[i - 1] = NULL;
	}
}

t_path	*solve(t_lem_info *data, int condition)
{
	t_path	*result;
	t_path	*tmp;
	int		score;

	get_path(getset_startmap(NULL), NULL);
	if ((result = cpy_and_add(NULL, get_set_shortest_way(NULL, 0))))
		remove_from_data(data->map, result->path);
	get_set_shortest_way(NULL, 1);
	while (condition && result)
	{
		score = calc_score(data->ants, result);
		get_path(getset_startmap(NULL), NULL);
		tmp = cpy_and_add(result, get_set_shortest_way(NULL, 0));
		if (tmp != result)
			remove_from_data(data->map, get_set_shortest_way(NULL, 0));
		get_set_shortest_way(NULL, 1);
		if (score <= calc_score(data->ants, tmp))
			clear_overpath(tmp, result, &condition);
		else
		{
			ft_freepath(result);
			result = tmp;
		}
	}
	return (result);
}
