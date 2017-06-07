/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:58:26 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/08 01:12:47 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTS_H
# define ANTS_H

# include "libft.h"

typedef struct		s_ants
{
	int				id;
	t_list			*map;
	struct s_ants	*next;
}					t_ants;

#endif
