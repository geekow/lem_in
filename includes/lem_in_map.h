/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:55 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/26 09:51:36 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_MAP_H
# define LEM_IN_MAP_H

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_map
{
	char			occuped;
	int				score;
	char			*name;
	t_coord			pos;
	struct s_map	*nextone;
	struct s_map	*nexttwo;
}					t_map;

#endif
