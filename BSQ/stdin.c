/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:35:30 by apuel             #+#    #+#             */
/*   Updated: 2017/11/13 18:52:56 by apuel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	pseudo_memcpy(char *out, char *in, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		out[i] = in[i];
		i++;
	}
}

char	*copy_stdin(void)
{
	char			buffer[4096];
	char			*temp;
	char			*input;
	int				br;
	unsigned int	buffer_size;

	input = (char *)0;
	buffer_size = 0;
	br = 1;
	while (br > 0)
	{
		br = read(0, buffer, 4096);
		temp = malloc(buffer_size + br + 1);
		if (temp && input)
			pseudo_memcpy(temp, input, buffer_size);
		if (input)
			free(input);
		input = temp;
		if (!input)
			break ;
		pseudo_memcpy(input + buffer_size, buffer, br);
		buffer_size += br;
		input[buffer_size] = '\0';
	}
	return (input);
}

void	bsq_stdin(void)
{
	char		*map;
	t_template	template;
	int			x;

	template.size = 0;
	if (setup_template(0, &template) && template.size && template.lines > 0)
	{
		map = copy_stdin();
		if (map)
		{
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
