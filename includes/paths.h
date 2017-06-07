/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 03:27:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/07 02:17:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

# include "lem_in.h"
# include "libft.h"

typedef struct	s_path
{
	int				deep;
	int				ants;
	t_list			*path;
	struct s_path	*next;
}				t_path;

#endif
