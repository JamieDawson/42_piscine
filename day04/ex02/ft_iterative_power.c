/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:33:13 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/28 19:35:40 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int p;
	int n;

	p = 1;
	n = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (p != power)
	{
		n *= nb;
		p++;
	}
	return (n);
}
