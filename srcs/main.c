/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:33:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 01:45:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int		error(void)
{
	ft_printf("ERROR");
	clear_all(NULL);
	return (-1);
}

int		main(void)
{
	t_lem_info	data;
	t_path		*result;

	parsing(&data, read_all());
	data.map = getset_startmap(NULL);
	if (!data.map || !getset_endmap(NULL))
		return (error());
	structure_data(data.map);
	result = solve(&data, 1);
	if (!result)
		return (error());
	print_result(result, data.ants);
	return (clear_all(result));
}
