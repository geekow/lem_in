/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:36:30 by user              #+#    #+#             */
/*   Updated: 2017/06/07 03:06:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		ft_lstlen(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

t_list	*ft_lstpushback(t_list *list, t_list *toadd)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = toadd;
	return (list);
}

t_list	*remove_conn_save_next(t_list **conns, t_list *prev, t_list *result,
	t_lem_map *toadd)
{
	t_list	*tmp;

	*conns = remove_connection(prev, *conns);
	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = toadd;
	tmp->next = NULL;
	if (!result)
		result = tmp;
	else
		ft_lstpushback(result, tmp);
	return (result);
}

void	advance_and_clear(t_list **list, char clear_content)
{
	t_list			*tmp;
	t_list			*tofree;
	t_current_map	*map;

	tmp = *list;
	tofree = *list;
	tmp = tmp->next;
	if (clear_content)
	{
		map = tofree->content;
		while (map->path)
			advance_and_clear(&map->path, 0);
		free(tofree->content);
	}
	free(tofree);
	*list = tmp;
}
