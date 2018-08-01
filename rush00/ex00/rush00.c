/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjha <pjha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:22:42 by pjha              #+#    #+#             */
/*   Updated: 2017/10/28 21:13:25 by pjha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LANG				"oooo-|-| "
#define TOP_LFT_CORNER		0
#define TOP_RGT_CORNER		1
#define BTM_RGT_CORNER		2
#define BTM_LFT_CORNER		3
#define TOP_BANK			4
#define RGT_BANK			5
#define BTM_BANK			6
#define LFT_BANK			7
#define FILLER				8

extern int	ft_putchar(char c);

static void	handle_left(int cy, int y)
{
	if (cy == 0)
		ft_putchar(LANG[TOP_LFT_CORNER]);
	else if (cy != (y - 1))
		ft_putchar(LANG[LFT_BANK]);
	else
		ft_putchar(LANG[BTM_LFT_CORNER]);
}

static void	handle_middle(int cy, int y)
{
	if (cy == 0)
		ft_putchar(LANG[TOP_BANK]);
	else if (cy != (y - 1))
		ft_putchar(LANG[FILLER]);
	else
		ft_putchar(LANG[BTM_BANK]);
}

static void	handle_right(int cy, int y)
{
	if (cy == 0)
		ft_putchar(LANG[TOP_RGT_CORNER]);
	else if (cy != (y - 1))
		ft_putchar(LANG[RGT_BANK]);
	else
		ft_putchar(LANG[BTM_RGT_CORNER]);
}

void		rush(int x, int y)
{
	int cx;
	int cy;

	cx = 0;
	cy = 0;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	while (cy < y)
	{
		while (cx < x)
		{
			if (cx == 0)
				handle_left(cy, y);
			else if (cx != (x - 1))
				handle_middle(cy, y);
			else
				handle_right(cy, y);
			cx++;
		}
		cx = 0;
		cy++;
		ft_putchar('\n');
	}
}
