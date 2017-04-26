/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:31:14 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 11:55:27 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*get_room(char *str)
{
	char	**tmp;
	t_map	*result;

	result = (t_map*)malloc(sizeof(t_map));
	if (!result)
		return (NULL);
	result->occuped = 0;
	result->score = 0;
	tmp = ft_split_whitespaces(str);
	if (!tmp || !tmp[0] || !tmp[1] || !tmp[2])
		return (NULL);
	result->name = tmp[0];
	result->pos.x = ft_atoi(tmp[1]);
	result->pos.y = ft_atoi(tmp[2]);
	return (result);
}
