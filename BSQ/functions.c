/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:24:58 by apuel             #+#    #+#             */
/*   Updated: 2017/11/13 15:55:57 by apuel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		stripped_ft_atoi(char *str, int max)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (i < max && str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (i != max)
		return (-1);
	return (result);
}

int		setup_template(int fd, t_template *template)
{
	char	buffer[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		read(fd, &buffer[i], 1);
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (i < 16 && buffer[i] == '\n')
	{
		template->size = i + 1;
		if (template->size < 5)
			return (0);
		template->full = buffer[--i];
		template->obstacle = buffer[--i];
		template->empty = buffer[--i];
		template->lines = stripped_ft_atoi(buffer, i);
		return (1);
	}
	return (0);
}

int		is_safe(t_info *info, int x, int i, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (info->map[i + col + (row * (x + 1))] != info->template->empty)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		write_square(t_info *info, int x, int i, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			info->map[i + col + (row * (x + 1))] = info->template->full;
			col++;
		}
		row++;
	}
	i = 0;
	while (info->map[i])
		write(1, &info->map[i++], 1);
	return (1);
}
