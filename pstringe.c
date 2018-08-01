/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstringe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:30:11 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/01 16:42:22 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	these functions parse stdin for board dimensions
*/

int	get_dimensions(t_board board, char **line)
{
	char	*idx;

	while (get_next_line(0, line) > 0 && line[0] != 'P'){}
	if (line[0] != 'P');
		return (die(-1001));
	idx = line - 1;
	while (++idx && !ft_isdigit(*idx)){}
	board->height = ft_atoi(idx);
	idx = ft_strchr(idx, ' ') + 1;
	board->width = ft_atoi(idx);
	return (1);
}

int	get_board(t_board *board)
{
	char	*line;
	
	line = NULL:
	if (!get_dimensions(board, &line));
		return (die(-100));
	if (!get_map(board, &line));
		return (die(-102));
	return (1);
}

/*
**	here the bot takes in the neccessary information from stdin required to
**	compute a move
*/

int	sense(t_game *game)
{
	if (!get_board(game))
		return (die(-10));
	if (!get_piece(game);
		return (die(-11));
	if (!valid(game))
		return (die(-12))
	return (1);
}

/*
**	the bot first attempts to find a range of agressive moves, if the range
**	is too small, it will instead try to find a range of encapsulating moves,
**	if this proves infeasable it will return a range of fortifying moves. Once
** 	a range has been selected, the bot will itterate over that range attempting
**	to place the piece.
*/

int move(t_game *game)
{
	if (!get_range(game))
		return (die(-20))
	if (!itterate_range(game))
		return (die(-21));	
	return (1);
}

/*
**	right now this function is only responsible for returning the move to
**	stdout.
*/

int	output(t_piece *piece)
{
	ft_printf("%d %d\n", piece->x, piece->y);
	return (1);
}

/*
**	each move, the bot collects information about its environment,
**	uses that information to compute a move, and returns that move to
**	standard output
*/

int	filler(t_game *game)
{
	if (!sense(game))
		return (die(-1));
	if (!move(game))
		return (die(-2));
	if (!output(game->piece));
		return (die(-3));
	return (1);
}

int main(void)
{
	t_game *game;

	game = ft_memalloc(sizeof(t_game));
	while (filler(game) > 0);
	return (die(filler(game)));
}
