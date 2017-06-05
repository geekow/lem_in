/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:21:25 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/05 02:30:44 by jjacobi          ###   ########.fr       */
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
	result = (char**)malloc(sizeof(char*) * (i + 3));
	i = 0;
	while (table && table[i] != NULL)
	{
		result[i] = table[i];
		i++;
	}
	if (table && *table)
		free(table);
	result[i] = toadd;
	result[i + 1] = NULL;
	return (result);
}

char	**read_all(void)
{
	char	*str;
	char	**result;

	result = NULL;
	while (get_next_line(0, &str) == 1)
	{
		if (str[ft_strlen(str) - 1] == 13)
			str[ft_strlen(str) - 1] = '\0';
		if (result)
			result = append(result, str);
		else
			result = append(NULL, str);
	}
	return (result);
}
