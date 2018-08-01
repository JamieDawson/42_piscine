/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:52:56 by jadawson          #+#    #+#             */
/*   Updated: 2017/10/31 16:13:21 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	unsigned	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - ((unsigned char)s2[i])));
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int len;
	int key_len;

	i = 0;
	len = ft_strlen(str);
	key_len = ft_strlen(to_find);
	while (i < len - key_len)
	{
		if (ft_strncmp(&str[i], to_find, key_len) == 0)
			return (&str[i]);
		i++;
	}
	return ((char *)0);
}
