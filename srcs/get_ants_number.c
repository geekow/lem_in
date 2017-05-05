/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:11:25 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/05 10:14:00 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lem_in.h"

int	get_ants_number(t_lem_info *data, char **readed)
{
	int	i;
	int	result;

	i = 0;
	while (readed[i] != NULL)
	{
		if (readed[i++][0] != '#')
		{
			result = ft_atoi(readed[i - 1]);
			if (ft_strlen(readed[i - 1]) == ft_strlen(ft_itoa(result)))
			{
				ft_putendl(readed[i - 1]);
				data->ants = result;
				return (i);
			}
			else
				return (-1);
		}
		ft_putendl(readed[i - 1]);
	}
	return (-1);
}
