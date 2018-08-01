/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:47 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/26 22:58:56 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printall(int a, int b, int c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a < '7' || b < '8' || c < '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a < '8')
	{
		b = a + 1;
		while (b < '9')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_printall(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
	ft_putchar('\n');
}
