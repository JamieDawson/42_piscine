/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:24:49 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/31 14:48:47 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int in_word;
	int i;

	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (in_word)
				str[i] += 32;
			in_word = 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!in_word)
				str[i] -= 32;
			in_word = 1;
		}
		else
			in_word = (str[i] >= '0' && str[i] <= '9');
		i++;
	}
	return (str);
}
