/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:42:50 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/30 12:55:02 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long long nnb;

	nnb = nb;
	if (nnb < 0)
	{
		ft_putchar('-');
		nnb = -nnb;
	}
	if (nnb >= 10)
	{
		ft_putnbr(nnb / 10);
		ft_putnbr(nnb % 10);
	}
	else
	{
		ft_putchar(nnb + '0');
	}
}
