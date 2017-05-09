/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:20:11 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/09 12:09:35 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

t_lem_map	*getset_startmap(t_lem_map *param)
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

t_lem_map	*get_room(char *name, char *str)
{
	char		**tmp;
	t_lem_map	*result;
	int			i;

	result = (t_lem_map*)malloc(sizeof(t_lem_map));
	if (!result)
		return (NULL);
	result->occuped = 0;
	tmp = ft_split_whitespaces(str);
	if (!tmp || !tmp[0] || !tmp[1])
		return (NULL);
	result->name = name;
	result->pos.x = ft_atoi(tmp[0]);
	result->pos.y = ft_atoi(tmp[1]);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (result);
}


int			reg_piece(char *name, char *line, char *prop)
{
	if (prop && ft_strcmp(prop, "start") == 0)
	{
		if (getset_startmap(get_room(name, line))) {
			;
		}
	}
	else if (prop && ft_strcmp(prop, "end") == 0) {
	//	if (-1 == regEndMap(name, line))
	}
	else
	{
	//	if (-1 == regMap(name, line))
	}
	return (1);
}
