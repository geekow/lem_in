/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:55:13 by user              #+#    #+#             */
/*   Updated: 2017/06/05 03:31:53 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

t_list	*get_next_maps(t_lem_map *map)
{
	t_list	*result;
	t_list	*tmp;
	int		i;

	i = 0;
	result = NULL;
	while (map && map->next && map->next[i])
	{
		if (!(tmp = malloc(sizeof(t_list))))
			return (NULL);
		tmp->content = map->next[i];
		tmp->next = NULL;
		if (!result)
			result = tmp;
		else
			ft_lstadd(&result, tmp);
		i++;
	}
	return (result);
}

void	print_map(t_lem_map *map)
{
	t_list		*current;
	t_list		*next;
	t_lem_map	*tmp;

	ft_printf("START:%s\n", map->name);
	current = get_next_maps(map);
	next = NULL;
	while (current)
	{
		while (current)
		{
			tmp = current->content;
			ft_printf("%s|", tmp->name);
			if (!next)
				next = get_next_maps(tmp);
			else
				ft_lstpushback(next, get_next_maps(tmp));
			current = current->next;
		}
		ft_printf("\n");
		current = next;
		next = NULL;
	}
}
