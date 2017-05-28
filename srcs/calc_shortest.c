/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:16:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/28 19:44:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "limits.h"

#include "ft_printf.h"

void debug(t_lem_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		ft_printf("Map name: %s\n", map->name);
		while (map->next[i])
		{
			ft_printf("		- Connection %d: %s\n", i, map->next[i]->name);
			i++;
		}
	}
	else
		ft_printf("Map is null");
}

t_list	*calc_shortest(t_lem_map *map)
{
	t_list		*result;
	t_list		*tmp;
	int			i;

	i = -1;
	result = NULL;
	if (!map)
		return (NULL);
	debug(map);
	while (map->next && map->next[++i])
	{
		if (map->next[i] == getset_endmap(NULL))
		{
			ft_printf("BEST PATH: %s\n", map->name);
			return (NULL);
		}
		else
		{
			if (!result)
			{
				if (!(result = (t_list*)malloc(sizeof(t_list))))
					return (NULL);
				result->content = (void*)map->next[i];
				result->next = NULL;
			}
			else
			{
				if (!(tmp = (t_list*)malloc(sizeof(t_list))))
					return (NULL);
				tmp->content = (void*)map->next[i];
				tmp->next = NULL;
				ft_lstpushback(result, tmp);
			}
		}
	}
	return (result);
}

void 	get_path(t_lem_map *start)
{
	t_list	*current;
	t_list	*next;

	next = NULL;
	current = calc_shortest(start);
	while (current)
	{
		while (current)
		{
			if (!calc_shortest((t_lem_map*)current->content))
			{
				ft_printf("WE FOUND THE BEST WAY MOTHER FUCKER\n");
				return;
			}
			if (!next)
				next = calc_shortest((t_lem_map*)current->content);
			else
				ft_lstpushback(next, calc_shortest((t_lem_map*)current->content));
			current = current->next;
		}
		current = next;
		next = NULL;
	}
}
