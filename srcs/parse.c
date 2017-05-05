/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:44:57 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/05 10:40:43 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

char*	regProp(char *param) {
	static char*	prop = NULL;
	char			*tmp;

	if (param == NULL)
	{
		tmp = ft_strdup(prop);
		prop = NULL;
		return (tmp);
	}
	else
	{
		prop = ft_strdup(param);
		return (NULL);
	}
}


int	treat_line(char	*buff)
{
	if (ft_strlen(buff) >= 2 && ft_strncmp(buff, "##", 2) == 0)
	{
		regProp(buff + 2);
		return (ft_printf("%s\n", buff));
	}
	else if (ft_strncmp(buff, "#", 1) == 0)
		return (ft_printf("%s\n", buff));
	else if (ft_strlen(buff) >= 3)
		return (analyse_line(regProp(NULL), buff));
	else
		return (-1);
}


int	parsing(t_lem_info *data, char **readed)
{
	int	i;

	if ((i = get_ants_number(data, readed)) == -1)
		return (-1);
	while (readed[i])
		if (treat_line(readed[i++]) == -1)
		{
			ft_printf("Fatal error on line : %i\n", i - 1);
			return (-1);
		}
	ft_printf("Treat_line function is over.\n");
		/**
		**	Build data structure with informations
		**/
	// if (get_start(data, readed) == -1)
	// 	return (-1);
	return (0);
}
