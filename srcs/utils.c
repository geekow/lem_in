/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:36:30 by user              #+#    #+#             */
/*   Updated: 2017/05/28 21:23:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void ft_lstpushback(t_list *list, t_list *toadd)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = toadd;
}

t_list	*remove_conn_save_next(t_list **conns, t_list *prev, t_list *result,
	t_lem_map *toadd)
{
	t_list	*tmp;

	*conns = remove_connection(prev, *conns);
	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = toadd;
	tmp->next = NULL;
	if (!result)
		result = tmp;
	else
		ft_lstpushback(result, tmp);
	return (result);
}
