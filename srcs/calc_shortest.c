/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:16:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/29 12:26:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "limits.h"

#include "ft_printf.h"

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
	else
	{
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
}

void	*print_path(t_list *path, char *last)
{
	t_list	*tmp;

	tmp = path;
	ft_printf("PATH:");
	while (tmp)
	{
		ft_printf("%s->	", (char*)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%s\n\n\n", last);
	return (NULL);
}

t_list	*calc_shortest(t_lem_map *map, t_list *path)
{
	t_list			*result;
	t_list			*tmp;
	t_current_map	*mapInfo;
	int				i;

	i = -1;
	result = NULL;
	while (map->next && map->next[++i])
	{
		if (map->next[i] == getset_endmap(NULL))
			return (print_path(path, map->name));
		else
		{
			if (!(tmp = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			if (!(mapInfo = (t_current_map*)malloc(sizeof(t_current_map))))
				return (NULL);
			mapInfo->map = map->next[i];
			mapInfo->path = add_to_path(path, map->name);
			tmp->content = (void*)mapInfo;
			tmp->next = NULL;
			if (!result)
				result = tmp;
			else
				ft_lstpushback(result, tmp);
		}
	}
	return (result);
}

void 	get_path(t_lem_map *start)
{
	t_list			*current;
	t_list			*next;
	t_current_map	*map;

	next = NULL;
	current = calc_shortest(start, NULL);
	while (current)
	{
		while (current)
		{
			map = current->content;
			if (!next)
				next = calc_shortest(map->map, map->path);
			else
				ft_lstpushback(next, calc_shortest(map->map, map->path));
			advance_and_clear(&current, 1);
		}
		current = next;
		next = NULL;
	}
}
