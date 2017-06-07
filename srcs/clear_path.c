/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 20:50:44 by user              #+#    #+#             */
/*   Updated: 2017/06/07 21:09:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_lst(t_list *tmp)
{
	t_list	*cache;

	while (tmp)
	{
		cache = tmp->next;
		free(tmp);
		tmp = cache;
	}
}

void	ft_freepath(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}

void	clear_path(t_path *path)
{
	t_path	*tmp;

	tmp = path;
	while (tmp)
	{
		clear_lst(tmp->path);
		tmp = tmp->next;
	}
	ft_freepath(path);
}

void	clear_overpath(t_path *path, t_path *cmp, int *tricky)
{
	t_path	*tmp;

	*tricky = 0;
	if (cmp == path)
		return ;
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	clear_lst(tmp->path);
	ft_freepath(path);
}
