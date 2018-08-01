/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:57:08 by apuel             #+#    #+#             */
/*   Updated: 2017/11/13 15:59:41 by apuel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_template
{
	int			lines;
	char		empty;
	char		obstacle;
	char		full;
	int			size;
}				t_template;

typedef struct	s_info
{
	char		*map;
	t_template	*template;
}				t_info;

int				setup_template(int fd, t_template *template);
int				is_safe(t_info *info, int x, int i, int size);
int				write_square(t_info *info, int x, int i, int size);
int				is_valid(char *map, t_template *template);
int				generate_square(char *map, t_template *template, int x, int y);
void			bsq_stdin(void);

#endif
