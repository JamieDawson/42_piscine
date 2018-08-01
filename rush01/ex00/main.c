/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:48:12 by pzhang            #+#    #+#             */
/*   Updated: 2017/11/05 23:36:04 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);

int		check_row(int row[9]) //takes a row, checks if it is sudoku legal, returns 0 for illegal, else 1.
{
	int c; //loops through array
	int n; //keeps track of which elements have been checked

	n = 0;
	while (n < 9) //checks for dups
	{
		c = n + 1;
		while (c < 9)
		{
			if (row[c] % 10 == row[n] % 10 && row[c] != 0) //use % 10 to keep track of input/numbers we put in
				return (0);
			c++;
		}
		n++;
	}
	return (1);
}

int     check_col (int row[9][9], int col_c) //column check
{
	int c;
	int n;

	n = 0;
	while (n < 9)
	{
		c = n + 1;
		while (c < 9)
		{
			if (row[c][col_c] % 10 == row[n][col_c] % 10 && row[c][col_c] != 0)
			{
				return (0);
			}
			c++;
		}
		n++;
	}
	return (1);
}

int		check_box(int row[9][9], int row_c, int col_c)
{
	int r_count;
	int c_count;
	int box[9];
	int n;

	r_count = row_c / 3;
	n = 0;
	while (r_count < row_c / 3 + 3)
	{
		c_count = col_c / 3;
		while (c_count < col_c / 3 + 3)
		{
			box[n] = row[r_count][c_count];
			c_count++;
			n++;
		}
		r_count++;
	}
	return (check_row(box));
}

int		check_all(int row[9][9])
{
	int count1;
	int count2;

	count1 = 0;
	while (count1 < 9) //checks all rows
	{
		if (check_row(row[count1]))
			count1++;
		else
			return (0);
	}
	count1 = 0;
	while (count1 < 9) //checks all cols
	{
		if(check_col(row, count1))
			count1++;
		else
			return (0);
	}
	count1 = 0;
	while (count1 < 7) //checks box for every box
	{
		count2 = 0;
		while (count2 < 7)
		{
			if(check_box(row, count1, count2))
				count2 += 3;
			else
				return (0);
		}
		count1 += 3;
	}
	return (1); //means it passed all tests
}

int		make_input(char **input, int row[9][9]) //puts input into int array if legal
{											//returns 0 if not legal, else returns 1
	int row_c;
	int col_c;

	row_c = 0;
	while (row_c < 9)
	{
		col_c = 0;
		while (col_c < 9)
		{
			if (input[row_c][col_c] != '.') //checks for actual numbers
				row[row_c][col_c] = input[row_c][col_c] - '0';
			else
				row[row_c][col_c] = 0; //replaces '.' with 0 for now; it makes check easier
			col_c++;
		}
		row_c++;
	}
	return (check_all(row)); //returns result of all 3 checks
}

int		make_row(int row[9][9], int row_num, int row_orig, int row_pos);

int		replace_prev(int row[9][9], int row_num, int row_orig, int pos) //replaces previous entry after finding error
{
	int count; //keeps track of which col (or element) in the row
	int num; //used for changing the number

	count = pos;
	while (count >= 0)
	{
		if (row[row_num][count] < 10 && row[row_num][count] != 0) //check if its original input, dont need to check 0 since going backwards
			count--;
		else
		{
			num = row[row_num][count] + 1;
			while (num < 20)
			{
				row[row_num][count] = num;
				if (check_row(row[row_num]), check_col(row, count), check_box(row, row_num, count)) //checks row/col/box
				{
					make_row(row, row_num, row_orig, count + 1);
					return (0); //if number works, return out of the fn, move back to make_row
				}
				row[row_num][count] -= 1;
				num++;
			}
			row[row_num][count] = 0;
			count--;
		}
	}
	if (row_num == 0 && count < 0) //means it can't go back anymore, puzzle is not solvable
		write(1, "Erro1", 5);	//prints error and ends
	else
		replace_prev(row, row_num - 1, row_orig, 8);
	return (0); //does nothing
}

int		make_row(int row[9][9], int row_num, int row_orig, int row_pos) //generates the number in puzzle
{							  //row number  //original row //column position in the row
	int count; //tracks which element in the row
	int num; //used for setting the number

	count = row_pos;
	while (count < 9)
	{
		if (row[row_num][count] < 10 && row[row_num][count] != 0) //make sure it's not original input
			count++;
		else //means the number is entered by us
		{
			if (row[row_num][count] == 0) //if no number at that spot or corrected by replace_prev
				num = 11;
			else
				num = row[row_num][count] + 1; //if there is a previous number
			while (num < 20)
			{
				row[row_num][count] = num;
				if (check_row(row[count]), check_col(row, count), check_box(row, row_num, count)) //checks row/col/box
					break ;
				else if (num < 20) //means number is no good but can still be good
				{
					row[row_num][count] -= 1;
					num++;
				}
				else //no possible matches, need to make backward corrections
				{
					row[row_num][count] = 0;
					replace_prev(row, row_num, row_orig, count - 1); //count - 1 to check starting from prev spot
					return (0); //need to break out of function here or recursive stacks will create errors
				}
			}
			count++;
		}
	}
	if (row_num < row_orig) //checks if we're back in the original row (replace_row could move to prev rows)
		make_row(row, row_num + 1, row_orig, 0);
	return (0); //does nothing, just like return (0) in main functions
}

int		check_arg(char **i) //checks argv params, assume argc = 10 since later in if cond.
{
	int c1;
	int c2;

	c1 = 0;
	while (c1 < 9)
	{
		if (ft_strlen(i[c1]) != 9) //str length check
			return (0);
		else
		{
			c2 = 0;
			while (i[c1][c2]) //checks if its only 1-9 digits and '.'
			{
				if (i[c1][c2] != '.' && !(i[c1][c2] >= '1' && i[c1][c2] <= '9'))
					return (0);
				c2++;
			}
		}
		c1++;
	}
	return (1);
}

void	print_result(int row[9][9])
{
	int count1;
	int count2;

	count1 = 0;
	while (count1 < 9)
	{
		count2 = 0;
		while (count2 < 9)
		{
			ft_putchar('0' + (row[count1][count2] % 10));
			count2++;
		}
		ft_putchar('\n');
		count1++;
	}
}

int		main(int argc, char **argv)
{
	int	row[9][9]; //2D int array in terms of row elements.
	int test;
	int row_count;

	row_count = 0;
	if (argc == 10 && check_arg(argv + 1)) //checks argv params
		test = make_input(argv + 1, row); //inputs params and checks if its legal, 1 for goood, 0 not good
	else
	{
		write(1, "Erro2", 5);
		return (0);
	}
	if (test == 0) //failed the check_all, print error message
	{
		write(1, "Erro3", 5);
		return (0);
	}
	else //means no mistakes w/ input parameters
	{
		while (row_count < 9)
		{
			make_row(row, row_count, row_count, 0); //makes the rows, goes back and forth to make numbers legal
			if (row[0][0] == 0) //checks if puzzle is still solvable
				break ;
			row_count++;
		}
		print_result(row); //prints results
	}
	return (0);
}
