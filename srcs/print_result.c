/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:05:40 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 02:41:23 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	advance(t_ants *ants)
{
	while (ants)
	{
		ants->map = ants->map->next;
		ants = ants->next;
	}
}

t_ants	*create_ants(int nb)
{
	t_ants	*result;
	t_ants	*tmp;
	int		i;

	i = 1;
	if (!(result = (t_ants*)malloc(sizeof(t_ants))))
		return (NULL);
	result->id = i++;
	result->map = NULL;
	result->next = NULL;
	tmp = result;
	while (i <= nb)
	{
		if (!(tmp->next = (t_ants*)malloc(sizeof(t_ants))))
			return (NULL);
		tmp->next->id = i++;
		tmp->next->map = NULL;
		tmp->next->next = NULL;
		tmp = tmp->next;
	}
	return (result);
}

void	add_ant(t_ants **all_ants, t_path *path)
{
	t_ants	*ant;

	ant = *all_ants;
	if (path->ants == 0 || !ant)
		return ;
	path->ants--;
	*all_ants = ant->next;
	ant->next = path->current;
	path->current = ant;
	ant->map = path->path->next;
}

int		remove_ended_ants(t_path *path)
{
	t_ants	*tmp;
	t_ants	*cache;

	if (!path || !path->current)
		return (0);
	if (path->current->map == NULL)
	{
		free(path->current);
		path->current = NULL;
		return (1);
	}
	cache = path->current;
	tmp = path->current->next;
	while (tmp)
	{
		if (tmp->map == NULL)
		{
			cache->next = tmp->next;
			free(tmp);
			return (1);
		}
		cache = tmp;
		tmp = tmp->next;
	}
	return (0);
}

void	print_result(t_path *path, int max)
{
	t_ants		*ants;
	t_path		*tmp;
	int			end;

	ants = create_ants(max);
	tmp = path;
	end = 0;
	while (tmp)
	{
		advance(tmp->current);
		add_ant(&ants, tmp);
		print_ants(tmp->current, tmp->next);
		end += remove_ended_ants(tmp);
		tmp = tmp->next;
		if (!tmp)
		{
			tmp = path;
			ft_printf("\n");
			if (end == max)
				return ;
		}
	}
}
