/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:45:14 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/02 13:20:46 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_range(int min, int max)
{
	int i;
	int *collect;

	i = 0;
	if (min >= max)
		return ((int *)0);
	if (min < max)
		collect = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		collect[i] = min;
		min++;
		i++;
	}
	return (collect);
}
