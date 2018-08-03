/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:11:13 by jadawson          #+#    #+#             */
/*   Updated: 2018/08/03 15:11:45 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}

/*
Test main() functions:


int main() //returns 3 because of wild card.
{
	char s1[10] = "abc";
	char s2[10] = "a**";
	printf("%d", nmatch(s1, s2));
	return 0;
}

int main ()	//returns 3 because of extra wild cards.
{
	char s1[10] = "a**";
	char s2[10] = "a**";
	printf ("%d", nmatch (s1, s2));
	return 0;
}

int main ()	//returns 6 because of extra wild card.
{
	char s1[10] = "abc";
	char s2[10] = "a***";
	printf ("%d", nmatch (s1, s2));
	return 0;
}

int main ()	//returns 0 because of comparing a and b.
{
	char s1[10] = "b**";
	char s2[10] = "a**";
	printf ("%d", nmatch (s1, s2));
	return 0;
}
