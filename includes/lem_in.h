/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/05 20:14:05 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_map.h"
# include "libft.h"

typedef struct	s_lem_info
{
	int			ants;
	t_lem_map	*map;
	char		*startname;
	char		*endname;
}				t_lem_info;

char			**read_all();
int				parsing(t_lem_info *data, char **readed);
int				get_ants_number(t_lem_info *data, char **readed);
int				analyse_line(char *prop, char *line);
int				reg_piece(char *name, char *line, char *prop);
int				reg_connection(char *name, char *line);
t_list			*getset_connection(t_list *all);


#endif
