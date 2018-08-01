/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:51:30 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/28 22:59:49 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if ((power == 0) || (nb == 1))
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	nb = nb * ft_recursive_power(nb, --power);
	return (nb);
}
