/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:20:11 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/05 12:01:20 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	reg_piece(char *name, char *line, char *prop)
{
	if (prop && ft_strcmp(prop, "start") == 0) {
	//	if (-1 == regStartMap(name, line))
			return (1);
	}
	else if (prop && ft_strcmp(prop, "end") == 0) {
	//	if (-1 == regEndMap(name, line))
			return (1);
	}
	else {
	//	if (-1 == regMap(name, line))
			return (1);
	}
	return (0);
}
