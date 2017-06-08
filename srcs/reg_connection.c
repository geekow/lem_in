/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 10:24:40 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 19:11:49 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*getset_connection(t_list *all, char reset)
{
	static t_list	*connections = NULL;

	if (reset)
		connections = NULL;
	if (all == NULL)
		return (connections);
	else
		connections = all;
	return (NULL);
}

t_list	*save_connection(char *name, char *line)
{
	t_list				*result;
	t_lem_connection	*cont;

	if (name[0] == 'L' || line[0] == 'L' || line[0] == '#' ||
		ft_strchr(line, ' ') || ft_strchr(line, '-'))
		return (NULL);
	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (result == NULL)
		return (NULL);
	if ((cont = (t_lem_connection*)malloc(sizeof(t_lem_connection))) == NULL)
		return (NULL);
	cont->one = name;
	cont->two = ft_strdup(line);
	result->content = (void*)cont;
	result->next = NULL;
	return (result);
}

int		reg_connection(char *name, char *line)
{
	t_list			*connections;
	t_list			*tmp;

	connections = getset_connection(NULL, 0);
	tmp = connections;
	if (!connections)
	{
		if (!(connections = save_connection(name, line)))
			return (-1);
		getset_connection(connections, 0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = save_connection(name, line);
		if (tmp->next == NULL)
			return (-1);
	}
	return (0);
}

t_list	*remove_connection(t_list *previous, t_list *list)
{
	t_list				*tmp;
	t_lem_connection	*connec;

	connec = (t_lem_connection*)list->content;
	if (previous)
		previous->next = list->next;
	else
	{
		if (list->next)
			getset_connection(list->next, 0);
		else
			getset_connection(NULL, 1);
	}
	tmp = list;
	list = list->next;
	free(tmp);
	free(connec->one);
	free(connec->two);
	free(connec);
	return (list);
}
