/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:11:25 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/29 13:29:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lem_in.h"

int	get_ants_number(t_lem_info *data, char **readed)
{
	int		i;
	int		result;
	char	*tmp;

	i = 0;
	while (readed[i] != NULL)
	{
		if (readed[i++][0] != '#')
		{
			result = ft_atoi(readed[i - 1]);
			tmp = ft_itoa(result);
			if (ft_strlen(readed[i - 1]) == ft_strlen(tmp))
			{
				ft_putendl(readed[i - 1]);
				data->ants = result;
				free(tmp);
				return (i);
			}
			free(tmp);
			return (-1);
		}
		ft_putendl(readed[i - 1]);
	}
	return (-1);
}
