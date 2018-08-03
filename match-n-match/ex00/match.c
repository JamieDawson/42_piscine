/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:53:54 by jadawson          #+#    #+#             */
/*   Updated: 2018/08/03 15:08:41 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == '*')
		return (match(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else
		return (0);
}

/*
test main() functions:

int main()  //returns 1 because * can be a anything.
{
  char s1[10] = "aaaa";
  char s2[10] = "****";
  printf("%d", match(s1, s2));
  return 0;
}


int main()  //returns 1 because * can be anything.
{
  char s1[10] = "a";
  char s2[10] = "****";
  printf("%d", match(s1, s2));
  return 0;
}


int main()  //returns 0 because 'c' and 'd' doesn't match.
{
  char s1[10] = "abc";
  char s2[10] = "abd";
  printf("%d", match(s1, s2));
  return 0;
}


int main()  //returns 1 because of wild card.
{
  char s1[10] = "abc";
  char s2[10] = "a*";
  printf("%d", match(s1, s2));
  return 0;
}

*/
