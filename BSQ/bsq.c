/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:02:57 by apuel             #+#    #+#             */
/*   Updated: 2017/11/13 18:52:42 by apuel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define IS_PARAM(x,y) (x == y->empty || x == y->obstacle)

unsigned int	get_size(char *path, t_template *template)
{
	int				fd;
	int				br;
	char			buffer[4096];
	unsigned int	result;

	result = 0;
	fd = open(path, O_RDONLY, 0);
	if (fd != -1)
	{
		if (!setup_template(fd, template))
			return (0);
		br = 1;
		while (br > 0)
		{
			br = read(fd, buffer, 4096);
			result += br;
		}
		close(fd);
		if (br == -1)
			return (0);
	}
	return (result);
}

int				is_valid(char *map, t_template *template)
{
	int x;
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
		if (map[i++] == '\n')
			j++;
	if (template->lines != j)
		return (-1);
	x = 0;
	while (map[x] != '\n' && map[x])
		x++;
	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n' && j == x)
			j = 0;
		else if (j++ > x || !IS_PARAM(map[i], template))
			return (-1);
		i++;
	}
	return (x);
}

int				generate_square(char *map, t_template *template, int x, int y)
{
	int		size;
	int		row;
	int		column;
	t_info	info;

	info.map = map;
	info.template = template;
	size = y;
	if (x < y)
		size = x;
	while (size)
	{
		row = -1;
		while (++row <= y - size)
		{
			column = -1;
			while (++column <= x - size)
				if (is_safe(&info, x, column + (row * (x + 1)), size))
					return (write_square(&info, x,
								column + (row * (x + 1)), size));
		}
		size--;
	}
	return (-1);
}

void			bsq(char *path)
{
	int				fd;
	unsigned int	size;
	t_template		template;
	int				x;
	char			*map;

	size = get_size(path, &template);
	if (size && template.size && template.lines > 0)
	{
		fd = open(path, O_RDONLY, 0);
		setup_template(fd, &template);
		if ((map = malloc(size + 1)))
		{
			read(fd, map, size);
			map[size] = '\0';
			close(fd);
			x = is_valid(map, &template);
			if (x != -1)
				x = generate_square(map, &template, x, template.lines);
			free(map);
			if (x != -1)
				return ;
		}
	}
	write(2, "map error\n", 10);
}

int				main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (i > 1)
				write(1, "\n", 1);
			bsq(argv[i++]);
		}
	}
	else
		bsq_stdin();
	return (0);
}
