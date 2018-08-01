/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:10:29 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/29 21:23:46 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	g_size = 0;

int		get_tab_length(int i)
{
	int res;

	res = 0;
	while (i < g_size)
	{
		res += 3 + i;
		if (i != g_size - 1)
			res += 2 + (i / 2);
		i++;
	}
	return (res - 1);
}

int		is_door(int len, int width, int j, int i)
{
	int	door_pos;

	door_pos = (width / 2) - (len / 2);
	if (i >= 0)
		return (j >= door_pos && j < door_pos + len && i == g_size - 1);
	else
		return (len >= 5 && j == door_pos + len - 2);
}

void	print_sastantua(int *height, int *width, int *i, int *pos)
{
	int j;
	int len;

	len = g_size + (g_size % 2) - 1;
	ft_putchar('/');
	j = 0;
	while (j < *width)
	{
		if (*pos >= *height - len && is_door(len, *width, j, *i))
		{
			if (*pos == *height - (len / 2) - 1 && is_door(len, *width, j, -1))
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else
			ft_putchar('*');
		j++;
	}
	ft_putchar('\\');
}

void	sastantua_inner(int *height, int *width, int *i, int *pos)
{
	int j;
	int whitespace;

	whitespace = get_tab_length(*i);
	j = 0;
	while (j < whitespace - *pos)
	{
		ft_putchar(' ');
		j++;
	}
	print_sastantua(height, width, i, pos);
	ft_putchar('\n');
	*width += 2;
	*pos += 1;
	if (*pos == *height)
	{
		*width += 4 + ((*i / 2) * 2);
		(*i)++;
		(*height)++;
		*pos = 0;
	}
}

void	sastantua(int size)
{
	int height;
	int width;
	int i;
	int pos;

	g_size = size;
	height = 3;
	width = 1;
	i = 0;
	pos = 0;
	while (i < size)
	{
		sastantua_inner(&height, &width, &i, &pos);
	}
}
