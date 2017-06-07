/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:05:40 by user              #+#    #+#             */
/*   Updated: 2017/06/07 22:51:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_result(t_path *path)
{
	static int		nbr = 1;
	int				i;
	int				y;
	t_list			*way;
	t_path			*tmp;

	tmp = path;
	i = 0;
	while (tmp)
	{
		if (nbr > path->ants)
			return ;
		way = tmp->path;
		y = 0;
		while (y < nbr && way->next)
		{
			way = way->next;
			y++;
		}
		ft_printf("L%d-%s", nbr + i, way->content);
		i++;
		tmp = tmp->next;
		if (tmp)
			ft_printf(" ");
	}
	ft_printf("\n");
	nbr++;
	print_result(path);
}
