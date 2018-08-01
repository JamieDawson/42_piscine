/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:00:55 by jadawson          #+#    #+#             */
/*   Updated: 2017/11/01 19:10:38 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(int argc, char **argv)
{
	int i;
	int x;

	i = 0;
	x = argc - 1;
	while (x > 0)
	{
		while (argv[x][i] != '\0')
		{
			ft_putchar(argv[x][i]);
			i++;
		}
		ft_putchar('\n');
		x--;
		i = 0;
	}
}

int		main(int argc, char **argv)
{
	if (argc >= 1)
		ft_print_params(argc, argv);
	return (0);
}
