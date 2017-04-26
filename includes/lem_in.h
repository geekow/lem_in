/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 11:54:44 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_map.h"
# include "libft.h"

typedef struct	s_info
{
	int			ants;
	t_map		*map;
	char		*startname;
	char		*endname;
}				t_info;

char			**read_all();
int				parse(t_info *data, char **readed);
t_map			*get_room(char *str);
int				get_ants_number(t_info *data, char **readed);
int				get_start(t_info *data, char **readed);

#endif
