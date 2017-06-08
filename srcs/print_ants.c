/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:35:28 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 02:36:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_ants(t_ants *ants, t_path *test)
{
	t_lem_map	*tmp;

	tmp = getset_endmap(NULL);
	while (ants)
	{
		if (ants->map == NULL)
		{
			if (!test && !ants->next)
				ft_printf("L%d-%s", ants->id, tmp->name);
			else
				ft_printf("L%d-%s ", ants->id, tmp->name);
		}
		else
		{
			if (!test && !ants->next)
				ft_printf("L%d-%s", ants->id, ants->map->content);
			else
				ft_printf("L%d-%s ", ants->id, ants->map->content);
		}
		ants = ants->next;
	}
}
