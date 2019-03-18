/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2019/03/18 15:23:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

/*
** Allocates an empty map string to populate with our pieces.
*/

char	*empty_map(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * (size));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

/*
** Displays a map as resolved by the program.
*/

void	print(t_etris *t, int count, int size)
{
	char	*str;
	int		x;
	int		y;

	str = empty_map(size);
	while (count > 0)
	{
		y = 0;
		while (y < t->height)
		{
			x = 0;
			while (x < t->width)
			{
				if ((t->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(t->y + y) * (size + 1) + x + t->x] = t->id;
				x++;
			}
			y++;
		}
		t++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

/*
** Utility die function
*/

int		die(char *str)
{
	ft_putendl(str);
	return (1);
}

/*
** Entry point for our application
*/

int		main(int argc, char **argv)
{
	t_etris		tetris[MAX_TETRI + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	if (argc != 2)
		return (die("usage: ./fillit [input_file]"));
	ft_bzero(tetris, sizeof(t_etris) * (MAX_TETRI + 1));
	if ((count = read_tetri(open(argv[1], O_RDONLY), tetris)) == 0)
		return (die("error"));
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = solve(tetris, count, map)) == 0)
		return (die("error"));
	print(tetris, count, size);
	return (0);
}



moving a piece right or left   ——>  right/left shift
moving a piece up or down      ——>  up/down is changing the row on the map we '&' from

A & B = checks whether we can place a piece (0 means we can else pieces collide)
A | B = fills the map with a piece (toggle on)
A ^ B = removes piece that has already been placed (toggle off)





						short_max = 32,767



					.#..      	0000 0000 0000 0000           0000 A000 0000 0000
					.#..      	0000 0000 0000 0000           0000 A000 0000 0000
					.##.      	0000 0000 0000 0000           0000 AA00 0000 0000
					....      	0000 0000 0000 0000           0000 0000 0000 0000


1000 0000 0000 0000
1000 0000 0000 0000
1000 0000 0000 0000
0100 0000 0000 0000



Way #1: move the piece to next index by 1 shift

piece >> 1

0100 0000 0000 0000
0100 0000 0000 0000
0110 0000 0000 0000
0000 0000 0000 0000



Way #2: move the

piece >> 1

0000 0000 0000 0000
1000 0000 0000 0000
1000 0000 0000 0000
1100 0000 0000 0000



													          (short) 1000 0000 0000 0000    = 32768
															  row = 0;
															  col = 0;

													          (short) 1000 0000 0000 0000    = 32768
															  row = 1;
															  col = 0;

													          (short) 1000 0000 0000 0000    = 32768
															  row = 2;
															  col = 0;

													          (short) 0100 0000 0000 0000    = 16384
															  row = 2;
															  col = 1;


					....    	0000 0000 0000 0000           0000 0000 0000 0000
					.##.    	0000 0000 0000 0000           0000 00BB 0000 0000
					..#.    	0000 0000 0000 0000           0000 000B 0000 0000
					..#.    	0000 0000 0000 0000           0000 000B 0000 0000



	t_uint16 map[16];


 map >> 1

        map >> 1
0x237623423 >> 1


	 A000 0000 0000 0000 A000 0000 0000 0000 AA00 0000 0000 0000 0000 0000 0000 0000
&	 A000 0000 0000 0000 A000 0000 0000 0000 AA00 0000 0000 0000 0000 0000 0000 0000
    —————————————————————————————————————————————————————————————————————————————————
     0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000


	!0 => COLLIDES (CANT PLACE IT)


i (index at which we place a piece) must remain less than 15


	while (BOARD_ROWS > CUR_ROW)
	{

		while (BOARD_COLS > CUR_COL)
		{

		}
	}

void 	fill_board(t_game tetromino)
{
	int row;
	int col____times_shifted;

	tetromino.board.size = // compute predicated start size;
	ft_bzero(tetromino.board.matrix, sizeof(tetromino.board.matrix));
	while (MAX_BOARD_SIZE >= tetromino.board.size)
	{
		row = -1;
		while (tetromino.board.size - tetromino.pieces[0].height >= ++row)
		{
			col____times_shifted = -1;
			while (tetromino.board.size - tetromino.pieces[0].width >= ++col____times_shifted)
			{
				if (((tetromino.pieces[0] >> col____times_shifted) & tetromino.board.matrix[row]) == 0) <==> if (PIECE_PLACEMENT_POSSIBLE == TRUE)
				{
					tetromino.board.matrix[row] = tetromino.pieces[0] ^ tetromino.board.matrix[row]; // <==> PLACE_PIECE(tetromino.pieces[0])
					place_next_piece(tetromino, 1);
					tetromino.board.matrix[row] = tetromino.pieces[0] ^ tetromino.board.matrix[row]; // <==> REMOVE_PIECE(tetromino.pieces[0])
				}
			}
		}
		++tetromino.board.size;
	}
}

void 	place_next_piece(t_game tetromino, t_uint8 i)
{
	int i;
	int row;
	int col____times_shifted;

	if (i == tetromino.num_pieces)
	{
		print_board(tetromino);
		exit(EXIT_SUCCESS);
	}
	row = -1;
	while (tetromino.board.size - tetromino.pieces[i].height >= ++row)
	{
		col____times_shifted = -1;
		while (tetromino.board.size - tetromino.pieces[i].width >= ++col____times_shifted)
		{
			if (((tetromino.pieces[i] >> col____times_shifted) & tetromino.board.matrix[row]) == 0) <==> if (PIECE_PLACEMENT_POSSIBLE == TRUE)
			{
				tetromino.board.matrix[row] = tetromino.pieces[i] ^ tetromino.board.matrix[row]; // <==> PLACE_PIECE(tetromino.pieces[i])
				place_next_piece(tetromino, i + 1);
				tetromino.board.matrix[row] = tetromino.pieces[i] ^ tetromino.board.matrix[row]; // <==> REMOVE_PIECE(tetromino.pieces[i])
			}
		}
	}
}


0001 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

1000 0000 0000 0000
1000 0000 0000 0000
1000 0000 0000 0000
1000 0000 0000 0000

# define INIT_BARRIER 9223512776490647552

FLOOR(
	ft_sqrt((sum(heights_of_all_pieces) * sum(widths_of_all_pieces)) / num_pieces)) =

0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

'..#.\n.###\n....\n....\n\n'

'....\n....\n..#.\n.###\n\n'
 0000  0000  0010  0111

(short) 0010 0000 0000 0000
(short) 0111 0000 0000 0000
(short) 0000 0000 0000 0000
(short) 0000 0000 0000 0000

0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000

0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

(t_uint64) curr_row = 0010 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000


piece_value = 0;


t_game	read_pieces(int fd)
{
	t_game tetromino;
	t_char buf[PIECE_SIZE];

}

t_piece	get_piece(t_char buf[PIECE_SIZE])
{
	int i;


	while (PIECE_ROWS > cur_row)
	{
		i = 19;
		while (0 < i)
		{
			piece_val &= (buf[i] == '#') ? 1 : 0;
			piece_val << 1;
		}

		if (cur_row > 0)
			piece_value >> 16;
		piece_value ^= curr_row;
	}
}




| 0000 0000 0000 0000 | 0100 0000 0000 0000 || 0111 0000 0000 0000 | 0000 0000 0000 0000    (t_uint64)


| 0000 0000 0000 0000 | 0100 0000 0000 0000 || 0000 0000 0000 0000 | 0111 0000 0000 0000 |  (t_uint32)




0000 0000 0000 0000
0100 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000

0000 0000 0000 0000
0111 0000 0000 0000
0100 0000 0000 0000
0000 0000 0000 0000



0000 0000 0000 0000 0000 0000 0000 0000 0100 0000 0000 0000 0111 0000 0000 0000


row[0] =  (short) piece_val
row[1] =  (short) piece_val >> 16
row[2] =  (short) piece_val >> 32
row[3] =  (short) piece_val >> 48
piece_val |= *((t_uint64 *)&row[0])


piece_val = 0000 0000 0000 0000
            0100 0000 0000 0000
            0111 0000 0000 0000
            0000 0000 0000 0000

official_piece = 0;

0000 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

official_piece = (short) piece_val | ((short) piece_val >> 16) | ((short) piece_val >> 32) | ((short) piece_val >> 48)


(short) rows[4];

row[0] =  0000 0000 0000 0000
row[1] =  0111 0000 0000 0000
row[2] =  0100 0000 0000 0000
row[3] =  0000 0000 0000 0000

piece_val =



0000 0000 0000 0000 | 0000 0000 0000 0000 |0000 0000 0000 0000 | 0000 0000 0000 0000
0000 0000 0000 0000 | 0000 0000 0000 0000 |0000 0000 0000 0000 | 0111 0000 0000 0000
0000 0000 0000 0000 | 0000 0000 0000 0000 |0000 0000 0000 0000 | 0100 0000 0000 0000
0000 0000 0000 0000 | 0000 0000 0000 0000 |0000 0000 0000 0000 | 0000 0000 0000 0000

0000 0000 0000 0000
0100 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000

row[0] =  *(short *) (&piece_val)
row[1] =  *(short *) (&piece_val + 2)
row[2] =  *(short *) (&piece_val + 4)
row[3] =  *(short *) (&piece_val + 6)

piece_val = *((t_uint64 *)&row[0])






————————————————————————————————————————————————————————————————————————————————————————————————
READING METHOD:

// ——————————————————————————————————————————————————————————————————————————————————————
PIECE:

....
.#..
.###
....

// ——————————————————————————————————————————————————————————————————————————————————————
PIECE READ AS A BUFFER:

'....\n.#..\n.###\n....\n\n'

// ——————————————————————————————————————————————————————————————————————————————————————
WHAT YOU WOULD THINK IT SHOULD LOOK LIKE AS A 64BIT INTEGER:

0000 0000 0000 0000
0100 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000

// ——————————————————————————————————————————————————————————————————————————————————————
WHAT YOU WOULD THINK IT SHOULD LOOK LIKE AS A 64BIT INTEGER:

1000 0000 0000 0000
1110 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000

// ——————————————————————————————————————————————————————————————————————————————————————
WHAT ITS ACTUALLY SUPPOSED TO LOOK LIKE AS A 64BIT INTEGER:

0000 0000 0000 0000
0000 0000 0000 0000
1110 0000 0000 0000
1000 0000 0000 0000

// ——————————————————————————————————————————————————————————————————————————————————————
WHAT ITS ACTUALLY SUPPOSED TO LOOK LIKE AS A FLATTENED 64BIT INTEGER:

0000 0000 0000 0000 | 0000 0000 0000 0000 | 1110 0000 0000 0000 | 1000 0000 0000 0000

// ——————————————————————————————————————————————————————————————————————————————————————

'....\n.#..\n.###\n....\n'

| 0000 0000 0000 0000 | 0100 0000 0000 0000 | 0111 0000 0000 0000 | 0000 0000 0000 0000 |







// ——————————————————————————————————————————————————————————————————————————————————————
PIECE:

....
.#..
.###
....

// ——————————————————————————————————————————————————————————————————————————————————————
PIECE READ AS A BUFFER:

'....\n.#..\n.###\n....\n\n'


// ——————————————————————————————————————————————————————————————————————————————————————
READING ALGO:

(reading from index 0 —> 19)

shift << 1
check if its a hash
place 1 or 0
x4 (for each character in a line)

shift << 12
x4 (for each line in buf)


// ——————————————————————————————————————————————————————————————————————————————————————
WHAT IT LOOKS LIKE AFTER READING IT INTO A 64BIT INTEGER:

0000 0000 0000 0000
0100 0000 0000 0000
0111 0000 0000 0000
0000 0000 0000 0000

// ——————————————————————————————————————————————————————————————————————————————————————
REVERSING ALGO:

row[0] =  (short) piece_val
row[1] =  (short) piece_val >> 16
row[2] =  (short) piece_val >> 32
row[3] =  (short) piece_val >> 48

piece_val = *((t_uint64 *)&row[0])


// ——————————————————————————————————————————————————————————————————————————————————————
WHAT IT LOOKS LIKE AFTER REVERSING IT:

0000 0000 0000 0000
0111 0000 0000 0000
0100 0000 0000 0000
0000 0000 0000 0000


// ——————————————————————————————————————————————————————————————————————————————————————
REPOSITION ALGO:


(using barriers)


// ——————————————————————————————————————————————————————————————————————————————————————
WHAT IT LOOKS LIKE AFTER CORRECTING IT:


'....\n.#..\n.###\n....\n\n'

row[0] = 0000 0000 0000 0000
row[1] = 0000 0000 0000 0000
row[2] = 0000 0000 0000 0000
row[3] = 0000 0000 0000 0000

....
.#..
.###
....

'....\n.#..\n.###\n....\n\n'

0000 0000 0000 0000


0000 0000 0000 0000
0000 0000 0000 0000
1110 0000 0000 0000
1000 0000 0000 0000


..#.
###.
....
....

'..#.\n###.\n....\n....\n\n'


get_piece

piece_val = 0;

{
	first = TRUE;
	{
		(short)tmp = 0010 0000 0000 0000

		if (buf[++i] == '#')    (check)
		{
			first = FALSE;
			tmp <<= 1;          (shift)
			tmp |= 1;           (place)
		}
		else
			if (first == TRUE)
				++zero; 1
		x4
	}
	if (tmp > 0)
		piece_val = ((piece_val << 16) | ((tmp << zero) << 12));
	x4
}




————————————————————————————————————————————————————————————————————————————————————————————————














0010 0111 0000 0000
piece_value = 0 ^ row1 ^ row2 ^ row3;


1000 0000 0000 0000
1000 0000 0000 0000
1100 0000 0000 0000
0000 0000 0000 0000

1000 0000 0000 0000 1000 0000 0000 0000 1100 0000 0000 0000 0000 0000 0000 0000

if (map is empty)
	XOR returns 1 (TRUE)
	XOR returns 0 (FALSE)



		A0BB 0000 0000 0000 A0BB 0000 0000 0000 AA00 0000 0000 0000 0000 0000 0000 0000
	&   0000 0000 0000 0000 0010 0000 0000 0000 1110 0000 0000 0000 0000 0000 0000 0000
	———————————————————————————————————————————————————————————————————————————————————
        0000 0000 0000 0000 0010 0000 0000 0000 1100 0000 0000 0000 0000 0000 0000 0000   != 0



0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 0000
0000 0000 0000 1111

0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111


												[.][.][.][.]
												[.][.][.][.]
												[.][.][.][.]
												[.][.][.][.]


																						*(uint64_t *)&matrix[i]

																						1000 0000 0000 0000   1000 0000 0000 0000   1100 0000 0000 0000   0000 0000 0000 0000

																						0000 0000 0000 0000   1100 0000 0000 0000   1000 0000 0000 0000   1000 0000 0000 0000
		     (short *)  map ——>	    (short) 	A000 0000 0000 0000	 	[0] 			0000 0000 0000 0000 | AA00 0000 0000 0000 | A000 0000 0000 0000 | A000 0000 0000 0000 |
					    			(short) 	A000 0000 0000 0000		[1]					   (short)               (short)               (short)               (short)
					    			(short) 	AA00 0000 0000 0000		[2]
					    			(short) 	0000 0000 0000 0000		[3]

					    			(short) 	0000 0000 0000 0000		[4]
					    			(short) 	0000 0000 0000 0000		[5]
					    			(short) 	0000 0000 0000 0000		[6]
					    			(short) 	0000 0000 0000 0000		[7]

									(short) 	0000 0000 0000 0000		[8]
					    			(short) 	0000 0000 0000 0000		[9]
					    			(short) 	0000 0000 0000 0000		[10]
					    			(short) 	0000 0000 0000 0000		[11]

					    			(short) 	0000 0000 0000 0000		[12]
					    			(short) 	0000 0000 0000 0000		[13]
					    			(short) 	0000 0000 0000 0000		[14]
					    			(short) 	0000 0000 0000 0000		[15]

    //  — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

					    			(short) 	0000 0000 0000 0000		[16]
					    			(short) 	0000 0000 0000 0000		[17]
					    			(short) 	0000 0000 0000 0000		[18]


											ABB0 0000 0000 0000
											A0B0 0000 0000 0000
											AAB0 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000
											0000 0000 0000 0000



											1000 0000 0000 0000
											1000 0000 0000 0000
											1000 0000 0000 0000
											1000 0000 0000 0000


typedef struct s_etris	t_etris;

struct				s_etris
{
	uint64_t			value;
	t_etris				*last;
	unsigned char		id;
	unsigned char		x;
	unsigned char		y;
	unsigned char		width;
	unsigned char		height;
};

int					read_tetri(const int fd, t_etris *tetris);
int					solve(t_etris *tetris, const int count, uint16_t *map);
int					check_piece(const t_etris *tetris, uint16_t *map);
void				toggle_piece(const t_etris *tetris, uint16_t *map);


















read_piece =
{
	0000 0000 0000 0000 0100 0000 0000 0000 0111 0000 0000 0000 0000 0000 0000 0000
}

(uint32_t)temp1 = read_piece >> 32
// temp1 =
// {
// 		0000 0000 0000 0000
// 		0100 0000 0000 0000
// }

(uint32_t)temp2 = (uint_32)read_piece;
// temp2 =
// {
// 		0111 0000 0000 0000
//		0000 0000 0000 0000
// }

temp1 = (temp1 << 16) | (temp1 >> 16);
// temp1 =
// {
// 		0000 0000 0000 0000			-->		0100 0000 0000 0000
// 		0100 0000 0000 0000			-->		0000 0000 0000 0000
// }

temp2 = (temp2 << 16) | (temp2 >> 16);
// temp1 =
// {
// 		0111 0000 0000 0000			-->		0000 0000 0000 0000
// 		0000 0000 0000 0000			-->		0111 0000 0000 0000
// }

read_piece = (t_uint64) temp2
// read_piece
// {
// 		0000 0000 0000 0000
// 		0000 0000 0000 0000
// 		0000 0000 0000 0000
// 		0111 0000 0000 0000
// }
read_piece = read_piece << 32
// read_piece
// {
// 		0000 0000 0000 0000
// 		0111 0000 0000 0000
// 		0000 0000 0000 0000
// 		0000 0000 0000 0000
// }
read_piece = read_piece | temp1
// read_piece
// {
// 		0000 0000 0000 0000
// 		0111 0000 0000 0000
// 		0100 0000 0000 0000
// 		0000 0000 0000 0000
// }

