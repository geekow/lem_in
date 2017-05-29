/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/29 12:40:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_map.h"
# include "libft.h"

# define CONNECTIONS getset_connection(NULL, 0)

typedef struct	s_lem_info
{
	int			ants;
	t_lem_map	*map;
	char		*startname;
	char		*endname;
}				t_lem_info;

typedef struct	s_current_map
{
	t_lem_map	*map;
	t_list		*path;
}				t_current_map;

char			**read_all();
int				parsing(t_lem_info *data, char **readed);
int				get_ants_number(t_lem_info *data, char **readed);
int				analyse_line(char *prop, char *line);
int				reg_piece(char *name, char *line, char *prop);
int				reg_connection(char *name, char *line);
int				store_piece_list(t_lem_map *store_piece_list);
int				structure_data(t_lem_map *map);
t_list			*remove_connection(t_list *previous, t_list *list);
t_list			*getset_connection(t_list *all, char reset);
t_list			*getset_map(t_list *param);
t_list			*remove_conn_save_next(t_list **conns, t_list *prev,
					t_list *result, t_lem_map *toadd);
t_list			*get_set_shortest_way(t_list *list, char *reset);
t_lem_map		*getset_startmap(t_lem_map *param);
t_lem_map		*getset_endmap(t_lem_map *param);
void 			get_path(t_lem_map *map);
void			print_map(t_lem_map *map);
void 			ft_lstpushback(t_list *list, t_list *toadd);
void			advance_and_clear(t_list **list, char clear_content);

#endif
