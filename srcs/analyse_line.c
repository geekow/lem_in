/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:17:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/05 11:34:42 by jjacobi          ###   ########.fr       */
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
		return (-1 == reg_piece(name, line + i + 1, prop) ? -1 :
													ft_printf("%s\n", line));
	else if (line[i] == '-' && (step = 1))
		return (-1 == reg_connection(name, line + i + 1) ? -1 :
													ft_printf("%s\n", line));
	else
		return (-1);
}
