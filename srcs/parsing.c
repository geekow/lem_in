/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:44:57 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 21:16:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

char	*regprop(char *param)
{
	static char		*prop = NULL;
	char			*tmp;

	if (param == NULL && prop)
	{
		tmp = ft_strdup(prop);
		free(prop);
		prop = NULL;
		return (tmp);
	}
	else
	{
		if (param)
			prop = ft_strdup(param);
		return (NULL);
	}
}

int		treat_line(char *buff)
{
	if (ft_strlen(buff) >= 2 && ft_strncmp(buff, "##", 2) == 0)
	{
		free(regprop(NULL));
		regprop(buff + 2);
		return (ft_printf("%s\n", buff));
	}
	else if (ft_strncmp(buff, "#", 1) == 0)
		return (ft_printf("%s\n", buff));
	else if (ft_strlen(buff) >= 3)
		return (analyse_line(regprop(NULL), buff));
	else
		return (-1);
}

int		free_readed(char **readed)
{
	int	i;

	i = 0;
	while (readed && readed[i])
		free(readed[i++]);
	free(readed);
	return (0);
}

int		parsing(t_lem_info *data, char **readed)
{
	int	i;

	if ((i = get_ants_number(data, readed)) == -1)
	{
		free_readed(readed);
		return (-1);
	}
	while (readed[i])
		if (treat_line(readed[i++]) == -1)
			break ;
	return (free_readed(readed));
}
