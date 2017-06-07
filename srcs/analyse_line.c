/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:17:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 01:31:57 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

char	*cpyandtronck(char *line, int i)
{
	char	*result;

	result = ft_strdup(line);
	result[i] = '\0';
	return (result);
}

int		catch_error(char *name, char *prop)
{
	if (name)
		free(name);
	if (prop)
		free(prop);
	return (-1);
}

int		analyse_line(char *prop, char *line)
{
	char		*name;
	int			i;
	static char	step = 0;

	i = 0;
	while (line[i] && (line[i] != ' ' && line[i] != '-'))
		i++;
	name = cpyandtronck(line, i);
	if (line[i] == ' ' && step == 0)
	{
		if (-1 == reg_piece(name, line + i + 1, prop))
			return (catch_error(name, prop));
	}
	else if (line[i] == '-' && (step = 1))
	{
		if (-1 == reg_connection(name, line + i + 1))
			return (catch_error(name, prop));
	}
	else
		return (-1);
	ft_printf("%s\n", line);
	if (prop)
		free(prop);
	return (1);
}
