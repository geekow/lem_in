/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:55 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/04 10:39:56 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_MAP_H
# define LEM_IN_MAP_H

typedef struct			s_lem_coord
{
	int					x;
	int					y;
}						t_lem_coord;

typedef struct			s_lem_connection
{
	char				*one;
	char				*two;
}						t_lem_connection;

typedef struct			s_lem_map
{
	char				occuped;
	int					score;
	char				*name;
	t_lem_coord			pos;
	struct s_lem_map	**next;
}						t_lem_map;

#endif
