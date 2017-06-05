/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 03:53:58 by jjacobi           #+#    #+#             */
/*   Updated: 2017/06/05 04:18:42 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	score_paths(int	ants, t_path *result)
{
	result->no_act = result->deep - result->prev_deep;
	if (ants - result->no_act > 0)
	
}
