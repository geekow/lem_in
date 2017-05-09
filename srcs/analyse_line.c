/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:17:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/09 11:47:53 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int	analyse_line(char *prop, char *line)
{
	char		*name;
	int 		i;
	static char	step = 0;

	i = 0;
	while (line[i] && (line[i] != ' ' && line[i] != '-'))
		i++;
	name = ft_strdup(line);
	name[i] = '\0';
	if (line[i] == ' ' && step == 0)
	{
		if (-1 == reg_piece(name, line + i + 1, prop))
			return (-1);
	}
	else if (line[i] == '-' && (step = 1))
	{
		if (-1 == reg_connection(name, line + i + 1))
			return (-1);
	}
	else
		return (-1);
	ft_printf("%s\n", line);
	if (prop)
		free(prop);
	free(name);
	return (1);
}
