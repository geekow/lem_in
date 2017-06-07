/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:33:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 20:32:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int		error(void)
{
	ft_printf("ERROR");
	clear_all(NULL);
	return (-1);
}

void	*print_path(t_list *path)
{
	t_list	*tmp;

	tmp = path;
	ft_printf("PATH:");
	while (tmp)
	{
		ft_printf("%s->	", (char*)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
	return (NULL);
}

void	print_result(t_path *path)
{
	if (!path)
	{
		ft_printf("No solution found\n");
		return ;
	}
	ft_printf("Ants numbers: %d\n", path->ants);
	ft_printf("Path len: %d\n", path->deep);
	print_path(path->path);
	if (path->next)
		print_result(path->next);
}

int		main(void)
{
	t_lem_info	data;
	t_path		*result;

	parsing(&data, read_all());
	data.map = getset_startmap(NULL);
	if (!data.map || !getset_endmap(NULL) || structure_data(data.map) == -1)
		return (error());
	result = solve(&data, 1);
	print_result(result);
	return (clear_all(result));
}
