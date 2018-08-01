/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:21:32 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/31 20:29:40 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	while (str[0])
	{
		if (!(str[0] >= 'a' && str[0] <= 'z'))
				return (0);
		str++;
	}
	return (1);
}