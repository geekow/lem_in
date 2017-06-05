/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 03:27:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/05 04:16:55 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

# include "lem_in.h"
# include "libft.h"

typedef struct	s_path
{
	int				deep;
	int				prev_deep;
	int				no_act;
	t_list			*path;
	struct s_path	*next;
}				t_path;

#endif
