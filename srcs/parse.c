/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:44:57 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 11:56:41 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse(t_info *data, char **readed)
{
	int	i;


	if (get_ants_number(data, readed) == -1)
		return (-1);
	if (get_start(data, readed) == -1)
		return (-1);
	return (0);
}
