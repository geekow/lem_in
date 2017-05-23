/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:48:50 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/23 22:18:40 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	store_piece_list(t_lem_map *store_piece_list)
{
	t_list	*result;
	t_list	*tmp;

	result = getset_map(NULL);
	if (!result)
	{
		if ((tmp = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (-1);
		tmp->content = (void*)store_piece_list;
		tmp->next = NULL;
		getset_map(tmp);
	}
	else
	{
		while (result->next)
			result = result->next;
		if ((result->next = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (-1);
		tmp = result->next;
		tmp->content = (void*)store_piece_list;
		tmp->next = NULL;
	}
	return (0);
}
