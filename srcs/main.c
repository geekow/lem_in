/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:33:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/04 11:42:08 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	error(void)
{
	return (-1);
}

int	main(void)
{
	t_lem_info	data;

	if (parsing(&data, read_all()) == -1)
		return (error());
	return (0);
}
