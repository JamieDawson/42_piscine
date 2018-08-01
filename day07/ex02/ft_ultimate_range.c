/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:29:05 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/02 16:03:57 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ultimate_range(int **range, int min, int max)
{
	int length;
	int count;

	length = (max - min);
	if (min >= max)
	{
		*range = ((int *)0);
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * length);
	if (*range)
	{
		count = 0;
		while (count < length)
		{
			range[0][count] = (min + count);
			count++;
		}
		return (length);
	}
	return (0);
}
