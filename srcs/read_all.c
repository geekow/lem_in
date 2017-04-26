/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:21:25 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 11:58:27 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**append(char **table, char *toadd)
{
	char	**result;
	int		i;

	i = 0;
	while (table && table[i] != NULL)
		i++;
	result = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (table && table[++i] != NULL)
		result[i] = table[i];
	if (table)
		free(table);
	result[i] = toadd;
	result[i + 1] = NULL;
	table = result;
	return (table);
}

char	**read_all()
{
	int		i;
	char	*str;
	char	**result;

	i = 1;
	result = NULL;
	while (i == 1)
	{
		i = get_next_line(STDIN_FILENO, &str);
		result = append(result, str);
	}
	return (result);
}
