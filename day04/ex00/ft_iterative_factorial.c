/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:40:46 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/28 18:16:54 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n2;
	int	count;

	n2 = 1;
	count = 1;
	if ((nb < 0) || (nb > 12))
		return (0);
	while (nb >= count)
	{
		n2 *= nb;
		nb--;
	}
	return (n2);
}
