/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:33:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/05 04:06:02 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int		error(void)
{
	ft_printf("ERROR");
	return (-1);
}

void	*print_path(t_list *path)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = path;
	ft_printf("\n\n\nPATH:");
	while (tmp)
	{
		i++;
		ft_printf("%s->	", (char*)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\nScore:%d\n\n\n", i);
	return (NULL);
}

int		main(void)
{
	t_lem_info	data;

	parsing(&data, read_all());
	data.map = getset_startmap(NULL);
	if (!data.map || structure_data(data.map) == -1)
		return (error());
	get_path(getset_startmap(NULL), NULL);
	print_path(get_set_shortest_way(NULL, 0));
	return (clear_all());
}


/**

	Solution
		if (rest(ants, solution))
			solution = solution + 1;

	Tans que score(Solution + 1) < score(Solution)
		solution = solution + 1;
	RESULT: SOLUTION

**/
